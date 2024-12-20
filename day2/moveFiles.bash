#!/bin/bash
cd ~/XYZ || exit
mkdir -p MyFile MyDir
for file in *; do
    if [ -f "$file" ]; then
        mv "$file" MyFile/
    elif [ -d "$file" ]; then
        mv "$file" MyDir/
    fi
done
echo "Files moved to MyFile and directories moved to MyDir."
