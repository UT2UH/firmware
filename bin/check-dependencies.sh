#!/usr/bin/env bash

# Note: This is a prototype for how we could add static code analysis to the CI.

set -e

if [[ $# -gt 0 ]]; then
    # can override which environment by passing arg
    BOARDS="$@"
else
    BOARDS="rak4631 rak4631_eink t-echo pca10059_diy_eink pico rak11200 tlora-v2 tlora-v1 tlora_v1_3 tlora-v2-1-1.6 tbeam heltec-v1 heltec-v2.0 heltec-v2.1 tbeam0.7 meshtastic-diy-v1 nano-g1 station-g1 m5stack-core m5stack-coreink tbeam-s3-core ut2uh-r6822dh ut2uh-k46v1 ut2uh-k46v2"
fi

echo "BOARDS:${BOARDS}"

CHECK=""
for BOARD in $BOARDS; do
     CHECK="${CHECK} -e ${BOARD}"
done

echo $CHECK

pio pkg outdated -e $CHECK
