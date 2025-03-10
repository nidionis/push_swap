#!/usr/bin/bash
#!/bin/bash

# Define combinations
combinations_2=("0 1" "1 0")
combinations_3=("0 1 2" "0 2 1" "1 0 2" "1 2 0" "2 0 1" "2 1 0")

make

# Function to test combinations
test_combinations() {
  local combinations=("$@")
  for combination in "${combinations[@]}"; do
    # Run your program with the combination and capture stderr
    ./push_swap $combination 2> error_log.txt
    echo "Tested combination: $combination"
    cat error_log.txt
  done
}

# Test 2-number combinations
test_combinations "${combinations_2[@]}"

# Test 3-number combinations
test_combinations "${combinations_3[@]}"
