#!/usr/bin/bash
if [ "$#" -ne 2 ]; then
    echo "Illegal number of parameters"
    exit 1
fi

filedir=$1
searchstr=$2

if [ -d "$filesir" ]; then
    echo "Given path is not a dir"
    exit 1
fi

files=`grep -r -l $searchstr $filedir | wc -l`
matches=`grep -r $searchstr $filedir | wc -l`
echo "The number of files are $files and the number of matching lines are $matches"


