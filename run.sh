#! /bin/bash

# TODO: make is overriding wrapper when collecting env vars to bypass make in dev test.
# SOLUTION: let wrapper copying keep the same time stats as the previous built to avoid that. Or, separately run that when the custom test thing is cre

set -u

error_exit()
{
    echo "Error ($0): $1"
    exit 1
}

muteria_runner=muteria
topdir=$(dirname $(readlink -f $0))


[ $# -eq 2 -o $# -eq 3 ] || error_exit "invalid number of arguments (expected 3, got $#)."
config_file=$1
muteria_output_dir=$2
collected_res=$topdir/collected_results
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

if [ $run_only_post -eq 0 ]; then
    KLEE_CHANGE_RUNTIME_SET_OLD_VERSION=on $muteria_runner --config $topdir/ctrl/conf.py --lang=c run || error_exit "pre failed!"
    
fi

# TDOD: Use a combination of TEST_TOOL_TYPES_SCHEDULING and RE_EXECUTE_FROM_CHECKPOINT_META_TASKS to re-execute for new
#$muteria_runner --config $topdir/ctrl/conf.py --lang=c run 



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
