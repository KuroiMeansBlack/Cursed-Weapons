#!/bin/bash
set -e

# Verify the path is set.
if [ -z "${RYU_PATH}" ]; then
    echo "RYU_PATH appears to not be set! Check your exlaunch.sh?"
    exit 1
fi

# Setup the path to the game's mods folder for Citron.
export EDEN_PATH="/home/kuroi/.local/share/eden/load/${PROGRAM_ID}/mods"
# Ensure directory exists.
mkdir -p ${EDEN_PATH}/exefs
if [ -d "${EDEN_PATH}/exefs" ]; then
    if [ "$(ls -A ${EDEN_PATH}/exefs)" ]; then
        echo "Removing the old contents"
        rm -rf "${EDEN_PATH}/exefs/*"
       
    fi
fi


cp -r ${OUT}/* ${EDEN_PATH}/exefs

echo "Files successfully copied to Citron mod directory."
