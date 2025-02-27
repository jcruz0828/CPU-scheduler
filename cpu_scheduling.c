#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void FCFS(int* burst_times, int num_processes);
void SJF(int* burst_times, int num_processes);
void RR(int* burst_times, int num_processes, int quantum);
