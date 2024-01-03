#!/bin/bash


while true
do
        ((run_count++))
    # Generate random values between 0 and 1 for the last two parameters
    seed=$RANDOM$RANDOM

    # Generate random values between 0 and 1 for the last two parameters
    param1=$(awk -v min=0 -v max=1 -v seed=$seed 'BEGIN{srand(seed); print min+rand()*(max-min)}')
    param2=$(awk -v min=0 -v max=1 -v seed=$((seed + 1)) 'BEGIN{srand(seed); print min+rand()*(max-min)}')

    threads=$(awk -v min=1 -v max=5 -v seed=$((seed + 3)) 'BEGIN{srand(seed); print int (min+rand()*(max-min))}')
    jobs=$(awk -v min=50 -v max=200 -v seed=$((seed + 4)) 'BEGIN{srand(seed); print int (min+rand()*(max-min))}')


    printf "Running with parameters: $param1 $param2 threads $threads jobs for threads $jobs id:$run_count \n"
    printf "./program ../datasets/1000000.bin 100 100 euclidean $param1 $param2 $threads $jobs $run_count \n" 
    ./program ../datasets/1000000.bin 100 100 euclidean $param1 $param2 $threads $jobs $run_count

    
done
