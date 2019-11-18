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


[ $# -eq 2 -o $# -eq 3 ] || error_exit "invalid number of arguments (expected 3, got $#)."
config_file=$1
muteria_output_dir=$2
collected_res=$muteria_output/collected_results
[ $# -eq 3 ] && collected_dir=$3

collected_pre=collected_dir/pre
collected_post=collected_dir/post

# After mart executes, this will collect the RESULTS folder
## Create the collected results dir
test -d $collected_dir || mkdir $collected_dir || error_exit "Failed to create collected_dir $collected_dir"

run_only_post=0
if test -d $collected_post; then
    run_only_post=1
fi

gather_data()
{
    m_dir=$1
    o_dir=$2
    pre_post=$3
    test -d m_dir || error_exit "m_dir missing ($m_dir)"
    test -d o_dir || error_exit "o_dir missing ($o_dir)"
    rm -rf $o_dir/*
    cp -rf $m_dir/latest/RESULTS_DATA $o_dir || error_exit "Failed to copy RESULTS_DIR"
    cp $m_dir/latest/testscases_workdir/shadow_se/klee_change_locs.json $o_dir || error_exit "Failed to copy klee_change_locs"
    
    test -d $m_dir/latest/RESULTS_DATA.$pre_post && rm -rf $m_dir/latest/RESULTS_DATA.$pre_post
    cp -rf $m_dir/latest/RESULTS_DATA $m_dir/latest/RESULTS_DATA.$pre_post
}

pre_conf=$config_file
post_conf=$config_file
tmp_post_conf=$collected_post/tmp_post_conf.py
if [ $run_only_post -eq 0 ]; then
    test -d $collected_pre || mkdir $collected_pre || error_exit "Failed to create collected_pre $collected_pre"
    KLEE_CHANGE_RUNTIME_SET_OLD_VERSION=on $muteria_runner --config $pre_conf --lang=c run || error_exit "pre failed!"
    gather_data $muteria_output_dir $collected_pre 'pre'
    
    # update post_conf 
    post_conf=$tmp_post_conf
    # Use a combination of TEST_TOOL_TYPES_SCHEDULING and RE_EXECUTE_FROM_CHECKPOINT_META_TASKS to re-execute for new        
    echo "import os, sys" > $tmp_post_conf
    echo "sys.path.insert(0, '$(dirname $config_file)')" >> $tmp_post_conf
    echo "from $(basename $config_file) import *" >> $tmp_post_conf
    echo "sys.path.pop(0)" >> $tmp_post_conf
    echo "import muteria.drivers.testgeneration as tc_driver" >> $tmp_post_conf
    echo "RE_EXECUTE_FROM_CHECKPOINT_META_TASKS = ['TESTS_EXECUTION_SELECTION_PRIORITIZATION']" >> $tmp_post_conf
    echo "try:" >> $tmp_post_conf
    echo "    tts = TEST_TOOL_TYPES_SCHEDULING" >> $tmp_post_conf
    echo "except NameError:" >> $tmp_post_conf
    echo "    tts = tc_driver.TEST_TOOL_TYPES_SCHEDULING" >> $tmp_post_conf
    echo "TEST_TOOL_TYPES_SCHEDULING = []" >> $tmp_post_conf
    echo "for tt in tts:" >> $tmp_post_conf
    echo "    TEST_TOOL_TYPES_SCHEDULING += list(tt)" >> $tmp_post_conf
    echo "TEST_TOOL_TYPES_SCHEDULING = [tuple(TEST_TOOL_TYPES_SCHEDULING)]" >> $tmp_post_conf
fi

test -d $collected_post || mkdir $collected_post || error_exit "Failed to create collected_post $collected_post"
$muteria_runner --config $post_conf --lang=c run || error_exit "post failed!"
gather_data $muteria_output_dir $collected_post 'post'

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
