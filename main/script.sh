#!/bin/bash
LC_NUMERIC="C"


while true
do
        ((run_count++))
    # Generate random values between 0 and 1 for the last two parameters
    seed=$RANDOM$RANDOM

    # Generate random values between 0 and 1 for the last two parameters
    param1=$(awk -v min=0.1 -v max=1 -v seed=$seed 'BEGIN{srand(seed); print min+rand()*(max-min)}')
    param2=$(awk -v min=0.0000 -v max=0.0001 -v seed=$((seed + 1)) 'BEGIN{srand(seed); print min+rand()*(max-min)}')
    projectiontree=$(awk -v min=1 -v max=500 -v seed=$((seed + 4)) 'BEGIN{srand(seed); print int (min+rand()*(max-min))}')
    threads=$(awk -v min=1 -v max=5 -v seed=$((seed + 5)) 'BEGIN{srand(seed); print int (min+rand()*(max-min))}')

    printf "Running with parameters: $param1 $param2 threads $threads jobs for threads $jobs id:$run_count \n"
    printf "/program ../datasets/100000.bin 400 400 improved $param1 $param2 $projectiontree $run_count $threads\n" 
    timeout 600 ./program ../datasets/100000.bin 400 400 improved $param1 $param2 $projectiontree $run_count $threads 

    if [ $? -eq 124 ]; then
        echo "Program terminated after reaching 5-minute timeout"
    fi
    
done
