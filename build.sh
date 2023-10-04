#!/bin/bash

<<'COMMENT'
if [[ $1 == "-run" ]]; then
    RUN=true
else
    RUN=false
fi
COMMENT

# The "ternary" of Bash:
RUN=$([[ $1 == "-run" ]] && echo true || echo false)
echo "$RUN"

# Create `build` if it doesn't exist:
mkdir -p "./build"

for file in ./*.c; do
    filename_no_ext="$(basename "$file" .c)"
    gcc -c "$file" -o "./build/$filename_no_ext.o"
done

gcc -c "./scan-api-impls/IoUtilsByBrahvim.c" -o "./build/IoUtilsByBrahvim.o"
