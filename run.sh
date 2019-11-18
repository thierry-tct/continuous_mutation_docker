#! /bin/bash

# TODO: make is overriding wrapper when collecting env vars to bypass make in dev test.
# SOLUTION: let wrapper copying keep the same time stats as the previous built to avoid that. Or, separately run that when the custom test thing is cre

set -u

if python -c "import muteria" > /dev/null; then
    pip install -U muteria # upgrade muteria if any new version is available
    muteria_runner=muteria
else
    muteria_dir='/home/mfi/mytools/muteria'
    muteria_runner=$muteria_dir/muteria/cli/run.sh
fi

topdir=$(dirname $(readlink -f $0))

if [ "${MART_BINARY_DIR:-}" != "" ]; then
    export PATH=$PATH:$MART_BINARY_DIR 
fi

#env > ~/abcdef

# After mart executes, this will collect the RESULTS folder
## Create the collected results dir
# TODO: Execute and collect for each output
collected_res=$topdir/collected_results

KLEE_CHANGE_RUNTIME_SET_OLD_VERSION=on $muteria_runner --config $topdir/ctrl/conf.py --lang=c run 

# TDOD: Use a combination of TEST_TOOL_TYPES_SCHEDULING and RE_EXECUTE_FROM_CHECKPOINT_META_TASKS to re-execute for new
#$muteria_runner --config $topdir/ctrl/conf.py --lang=c run 

exit $?
