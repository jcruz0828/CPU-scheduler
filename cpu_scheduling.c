#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void FCFS(int* burst_times, int num_processes);
void SJF(int* burst_times, int num_processes);
void RR(int* burst_times, int num_processes, int quantum);
void bubbleSortWithIds(int* arr, int*id, int n);
#define swap(a,b) {int temp = a; a = b; b = temp;}

int main() {
  // Declare variables
  int num_processes = 0;
  int* burst_times;

  // Ask the user for the number of processes to run
  // HINT: use scanf for user input
   printf("Enter Number of Processes: ");
   scanf("%d",&num_processes);
   burst_times = (int* )malloc(num_processes*sizeof(int));

   for(int i = 0;i<num_processes;++i){
    printf("Enter burst time of Processes %d: ",i+1);
    scanf("%d",&burst_times[i]);
   }
  // Allocate memory for burst times
  // HINT: use malloc to allocate memory

  // Enter the burst times for each process
  // HINT: use scanf within a for loop

  // OPTIONAL: Print out the process burst times

  // Call each scheduling algorithm
  // Each call should have the burst times and number of processes passed in
  // Round-robin also needs a quantum passed in.
    //FCFS(burst_times, num_processes);   // Uncomment only when ready!
   // SJF(burst_times, num_processes);    // Uncomment only when ready!
    RR(burst_times, num_processes, 2);  // Uncomment only when ready!

  // Deallocate memory
  free(burst_times);
  // Return
  return 0;
}

// First-come-first-served CPU scheduling
void FCFS(int* burst_times, int num_processes) {
  // Declare variables
  int time_elapsed = 0;
  float avg_waiting_time = 0.0f;
  float avg_turnaround_time = 0.0f;
  int wait_time = 0;
  int turnaround_time = 0;

  for(int i = 0;i<num_processes;++i){
    turnaround_time = time_elapsed + burst_times[i];
    wait_time = turnaround_time - burst_times[i];
    time_elapsed = turnaround_time;
    avg_waiting_time += wait_time;
    avg_turnaround_time += turnaround_time;
    printf("Process %d: Waiting Time: %d, Turnaround Time: %d\n",i+1,wait_time,turnaround_time);
  }
  avg_waiting_time /= num_processes;
  avg_turnaround_time /= num_processes;
  printf("Average Waiting Time: %f\n",avg_waiting_time);
  printf("Average Turnaround Time: %f\n",avg_turnaround_time);
  // Iterate through the burst times in a for loop.
  // For each burst time (BT), add to the elapsed time and
  // calculate and print the waiting time (WT) and turnaround
  // time (TAT) for that process. Note:
  // TAT = TimeFinished - TimeSubmitted
  // WT = TAT - BurstTime

  // Calculate and print average waiting and turnaround times.

  return;
}



// Shortest-job-first CPU scheduling calculator
void SJF(int* burst_times, int num_processes) {

  // Declare pointers and variables
  int* sorted_burst_times = (int*)malloc(num_processes * sizeof(int));
  int* process_ids = (int*)malloc(num_processes * sizeof(int));
  int time_elapsed = 0;
  float avg_waiting_time = 0.0f;
  float avg_turnaround_time = 0.0f;
  int wait_time = 0;
  int turnaround_time = 0;


  for(int i = 0;i<num_processes;++i){
    sorted_burst_times[i] = burst_times[i];
    process_ids[i] = i+1;
  }
  bubbleSortWithIds(sorted_burst_times,process_ids,num_processes);
  for(int i = 0;i<num_processes;++i){
    turnaround_time = time_elapsed + sorted_burst_times[i];
    wait_time = turnaround_time - sorted_burst_times[i];
    time_elapsed = turnaround_time;
    avg_waiting_time += wait_time;
    avg_turnaround_time += turnaround_time;
    printf("Process %d: Waiting Time: %d, Turnaround Time: %d\n",process_ids[i],wait_time,turnaround_time);
  }
  avg_waiting_time /= num_processes;
  avg_turnaround_time /= num_processes;
  printf("Average Waiting Time: %f\n",avg_waiting_time);
  printf("Average Turnaround Time: %f\n",avg_turnaround_time);
  // In a for loop, copy burst times to new array to be sorted
  // and populate the array of process IDs.

  // Sort burst times using a sorting algorithm. For each swap
  // between positions i and j in the sorted burst times, the
  // same swap is done for positions i and j in the process IDs.
  // This not only sorts burst times, but keeps track of which
  // burst time corresponded to each process.

  // Iterate through the sorted burst times in a for loop, much
  // like how it was done for FCFS. For each sorted burst time,
  // print the process ID (from the array of PIDs), waiting time,
  // and turnaround time.

  // Calculate and print average waiting and turnaround times.

  // Deallocate memory

  // Return
  free(sorted_burst_times);
  free(process_ids);
  return;
}

// Round-robin CPU scheduling calculator
void RR(int* burst_times, int num_processes, int quantum) {

  // Declare variables and pointers
  int* time_remaining = (int*)malloc(num_processes * sizeof(int));
  int time_elapsed = 0;
  bool all_processes_complete = false;
  float avg_waiting_time = 0.0f;
  float avg_turnaround_time = 0.0f;
  
  for(int i = 0;i<num_processes;++i){
    time_remaining[i] = burst_times[i];
  }
  // Perform the following while loop until all processes have finished.
  while (!all_processes_complete) {
    // First loop: loop through time_remaining
    for (int i = 0; i < num_processes; i++) {
        // If a process's time remaining is already zero, skip it.
        if (time_remaining[i] == 0) continue;

        // Calculate how long the current quantum will be. If the process's
        // remaining time is shorter than the quantum, the current quantum
        // is the remaining time. Otherwise, it's the value of the quantum
        // parameter passed in.
        int current_quantum = quantum;
        if (time_remaining[i] < current_quantum) {
            current_quantum = time_remaining[i];
        }
        time_elapsed += current_quantum;
        time_remaining[i] -= current_quantum;
        // Increment the elapsed time by the current quantum and
        // decrement the current quantum from the time remaining.

        // Check whether the process now has a remaining time of zero. If so,
        // then the process has finished and its waiting and turnaround
        // times are calculated and printed. Add these times to
        // avg_waiting_time and avg_turnaround_time for calculating averages.
        if (time_remaining[i] == 0) {
            int wait_time = time_elapsed - burst_times[i];
            int turnaround_time = wait_time + burst_times[i];
            avg_waiting_time += wait_time;
            avg_turnaround_time += turnaround_time;
            printf("Process %d: Waiting Time: %d, Turnaround Time: %d\n", i + 1, wait_time, turnaround_time);
        }
    }

    // Second loop: check whether every process has finished
    all_processes_complete = true;
    for (int i = 0; i < num_processes; i++) {
        all_processes_complete = all_processes_complete && time_remaining[i] == 0;
    }
  }

  // Calculate and print average waiting and turnaround times.
  avg_waiting_time /= num_processes;
  avg_turnaround_time /= num_processes;
  printf("Average Waiting Time: %f\n", avg_waiting_time);
  printf("Average Turnaround Time: %f\n", avg_turnaround_time);
  free(time_remaining);
  // Return
  return;
}

  

void bubbleSortWithIds(int* arr, int*id, int n){
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++) {
      swapped = false;
      for (j = 0; j < n - i - 1; j++) {
          if (arr[j] > arr[j + 1]) {
              swap(arr[j], arr[j + 1]);
              swap(id[j], id[j + 1]);
              swapped = true;
          }
      }

      // If no two elements were swapped by inner loop,
      // then break
      if (swapped == false)
          break;
  }
}