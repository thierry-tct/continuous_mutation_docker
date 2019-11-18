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

gather_data()
{
    m_dir=$1
    o_dir=$2
    # TODO: implement
}

post_conf=$topdir/ctrl/conf.py
if [ $run_only_post -eq 0 ]; then
    test -d $collected_pre || mkdir $collected_pre || error_exit "Failed to create collected_pre $collected_pre"
    KLEE_CHANGE_RUNTIME_SET_OLD_VERSION=on $muteria_runner --config $topdir/ctrl/conf.py --lang=c run || error_exit "pre failed!"
    gather_data $muteria_output_dir $collected_pre
    
    # update post_conf 
    post_conf=$collected_post/tmp_post_conf.py
    # TODO: populate tmp_post_conf.py
    # TODO: Use a combination of TEST_TOOL_TYPES_SCHEDULING and RE_EXECUTE_FROM_CHECKPOINT_META_TASKS to re-execute for new
fi

test -d $collected_post || mkdir $collected_post || error_exit "Failed to create collected_post $collected_post"
$muteria_runner --config $post_conf --lang=c run || error_exit "post failed!"
gather_data $muteria_output_dir $collected_post

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
