#!/usr/bin/bash
if [ "$#" -ne 2 ]; then
    echo "Illegal number of parameters"
    exit 1
fi

file=$1
str=$2


mkdir -p "$(dirname "$file")" && touch "$file"
echo "$str" > $file
