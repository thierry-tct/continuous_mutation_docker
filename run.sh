#! /bin/bash

# This scripts run the experiment for a particular commit and 
# save the outputs of original and mutants on the pre and post commit versions
# 
# The arguments of the script are:
# - muteria config file for the project
# - path to the folder specified as output in the muteria config file
# - path to the (non existing) directory where the experiment output data is to be stored.
# e.g.: run.sh ctrl/conf.py output collected
#########

set -u

error_exit()
{
    echo "Error ($0): $1"
    exit 1
}

sudo pip install -U muteria

muteria_runner=muteria
topdir=$(dirname $(readlink -f $0))


[ $# -eq 2 -o $# -eq 3 ] || error_exit "invalid number of arguments (expected 2 or 3, got $#)."
config_file=$1
muteria_output_dir=$2
collected_dir=$(dirname $(readlink -f muteria_output_dir))/collected_results
[ $# -eq 3 ] && collected_dir=$3

# After mart executes, this will collect the RESULTS folder
## Create the collected results dir
test -d $collected_dir || mkdir $collected_dir || error_exit "Failed to create collected_dir $collected_dir"

first='post'
second='pre'

collected_first=$collected_dir/$first
collected_second=$collected_dir/$second

run_only_second=0
if test -d $collected_second; then
    run_only_second=1
fi

gather_data()
{
    m_dir=$1
    o_dir=$2
    pre_post=$3
    test -d $m_dir || error_exit "m_dir missing ($m_dir)"
    test -d $o_dir || error_exit "o_dir missing ($o_dir)"
    rm -rf $o_dir/*
    cp -rf $m_dir/latest/RESULTS_DATA $o_dir || error_exit "Failed to copy RESULTS_DIR"
    if [ "$pre_post" = "$first" ]; then
	if test -f $m_dir/latest/testscases_workdir/shadow_se/klee_change_locs.json ; then
            cp $m_dir/latest/testscases_workdir/shadow_se/klee_change_locs.json $o_dir || error_exit "Failed to copy klee_change_locs"
        fi
        if test -d $m_dir/latest/criteria_workdir/mart_0/instrumented_code/mutant_data/mart-out-0/ ; then
            cp -rf $m_dir/latest/criteria_workdir/mart_0/instrumented_code/mutant_data/mart-out-0/ $o_dir || error_exit "Failed to copy mutantsInfos.jsom"
	fi
    fi
    
    test -d $m_dir/latest/RESULTS_DATA.$pre_post && rm -rf $m_dir/latest/RESULTS_DATA.$pre_post
    cp -rf $m_dir/latest/RESULTS_DATA $m_dir/latest/RESULTS_DATA.$pre_post || error_exit "backing result_data failed"

    if [ "$pre_post" = "$first" ]; then
	rm -rf $m_dir/latest/RESULTS_DATA || error_exit "rm result data failed (pre)"
    fi
}

first_conf=$config_file
second_conf=$config_file
tmp_post_conf=$collected_dir/tmp_post_conf.py
jump=''

if [ $run_only_second -eq 0 ]; then
    echo ">>>>>"
    echo "RUNNING $first"
    echo "<<<<<"
    test -d $collected_first || mkdir $collected_first || error_exit "Failed to create collected_$first $collected_first"

    if [ "$first" = 'pre' ]; then
        yes | KLEE_CHANGE_RUNTIME_SET_OLD_VERSION=on $muteria_runner --config $first_conf --lang=c run || error_exit "$first failed!"
    else
        yes | $muteria_runner --config $first_conf --lang=c run || error_exit "$first failed!"
    fi

    gather_data $muteria_output_dir $collected_first $first

    jump="RE_EXECUTE_FROM_CHECKPOINT_META_TASKS = ['TESTS_EXECUTION_SELECTION_PRIORITIZATION']" 
fi


# update second_conf 
second_conf=$tmp_post_conf
# Use a combination of TEST_TOOL_TYPES_SCHEDULING and RE_EXECUTE_FROM_CHECKPOINT_META_TASKS to re-execute for new        
echo "import os, sys" > $tmp_post_conf
echo "sys.path.insert(0, '$(dirname $config_file)')" >> $tmp_post_conf
echo "from $(basename ${config_file%.py}) import *" >> $tmp_post_conf
echo "sys.path.pop(0)" >> $tmp_post_conf
echo "import muteria.drivers.testgeneration as tc_driver" >> $tmp_post_conf
echo "$jump" >> $tmp_post_conf
echo "try:" >> $tmp_post_conf
echo "    tts = TEST_TOOL_TYPES_SCHEDULING" >> $tmp_post_conf
echo "except NameError:" >> $tmp_post_conf
echo "    tts = tc_driver.TEST_TOOL_TYPES_SCHEDULING" >> $tmp_post_conf
echo "TEST_TOOL_TYPES_SCHEDULING = []" >> $tmp_post_conf
echo "for tt in tts:" >> $tmp_post_conf
echo "    TEST_TOOL_TYPES_SCHEDULING += list(tt)" >> $tmp_post_conf
echo "TEST_TOOL_TYPES_SCHEDULING = [tuple(TEST_TOOL_TYPES_SCHEDULING)]" >> $tmp_post_conf


echo ">>>>>"
echo "RUNNING $second"
echo "<<<<<"
test -d $collected_second || mkdir $collected_second || error_exit "Failed to create collected_second $collected_second"

if [ "$second" = 'pre' ]; then
    yes | KLEE_CHANGE_RUNTIME_SET_OLD_VERSION=on $muteria_runner --config $second_conf --lang=c run || error_exit "$second failed!"
else
    yes | $muteria_runner --config $second_conf --lang=c run || error_exit "$second failed!"
fi

gather_data $muteria_output_dir $collected_second $second

test -f $tmp_post_conf && rm -f $tmp_post_conf

echo "# ($0) DONE!"



##############################################
##############################################

#if python -c "import muteria" > /dev/null; then
#    pip install -U muteria # upgrade muteria if any new version is available
#    muteria_runner=muteria
#else
#    muteria_dir='/home/mfi/mytools/muteria'
#    muteria_runner=$muteria_dir/muteria/cli/run.sh
#fi

#if [ "${MART_BINARY_DIR:-}" != "" ]; then
#    export PATH=$PATH:$MART_BINARY_DIR 
#fi

#env > ~/abcdef




#KLEE_CHANGE_RUNTIME_SET_OLD_VERSION=on $muteria_runner --config $topdir/ctrl/conf.py --lang=c run 

# TDOD: Use a combination of TEST_TOOL_TYPES_SCHEDULING and RE_EXECUTE_FROM_CHECKPOINT_META_TASKS to re-execute for new
#$muteria_runner --config $topdir/ctrl/conf.py --lang=c run 

#exit $?
