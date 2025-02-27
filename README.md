# CPU Scheduling Algorithms

## Overview
This project implements three fundamental CPU scheduling algorithms:
1. **First-Come, First-Served (FCFS)**
2. **Shortest Job First (SJF)**
3. **Round Robin (RR)**

These algorithms are used to determine the execution order of processes based on their burst times.

## Features
- Reads the number of processes and their burst times from the user.
- Implements different scheduling policies to simulate process execution.
- Displays the scheduling results, including waiting times and turnaround times.

## Files
- `main.c` - The main driver program that handles user input and calls the scheduling algorithms.
- `scheduling.h` - Header file containing function prototypes.
- `scheduling.c` - Implementation of the scheduling algorithms.

## Compilation & Execution
To compile the program, use:
```bash
gcc main.c scheduling.c -o scheduler
```

To run the program:
```bash
./scheduler
```

## Usage
1. Enter the number of processes.
2. Enter the burst times for each process.
3. Choose the scheduling algorithm to execute.
4. View the scheduling results.

## Scheduling Algorithms
### First-Come, First-Served (FCFS)
- Processes are executed in the order they arrive.

### Shortest Job First (SJF)
- The process with the shortest burst time is executed first.

### Round Robin (RR)
- Each process is given a fixed time slice (quantum), and execution cycles through the processes until completion.

## License
This project is open-source and available for modification and redistribution under the MIT License.
