#!/bin/bash

# BUSY_TIME and IDLE_TIME in milliseconds
BUSY_TIME=10
IDLE_TIME=990

# Function to perform a busy-wait
busy_wait() {
    local end=$(( $(date +%s%3N) + $BUSY_TIME ))
    while [ $(date +%s%3N) -lt $end ]; do :; done
}

# Main loop to simulate CPU load
while true; do
    busy_wait
    sleep $(echo "scale=3; $IDLE_TIME/1000" | bc)
done

