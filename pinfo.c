/*
 * Name: Carla Sastre
 * Assignment: Lab 9 - System Calls
 * Section: CPE2600 - 2025S1
 */

#define _GNU_SOURCE  // Enable GNU extensions for sched.h compatibility
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>

/**
 * Function to print the scheduling policy in a human-readable format.
 */
void print_scheduler(int policy) {
    switch (policy) {
        case SCHED_OTHER: printf("Scheduling policy: SCHED_OTHER\n"); break;
        case SCHED_FIFO: printf("Scheduling policy: SCHED_FIFO\n"); break;
        case SCHED_RR: printf("Scheduling policy: SCHED_RR\n"); break;
        default: printf("Unknown scheduling policy\n"); break;
    }
}

int main(int argc, char *argv[]) {
    // Determine if a process ID (PID) was provided as a command-line argument
    // If no argument is provided, default to the current process ID
    pid_t pid = (argc > 1) ? atoi(argv[1]) : getpid();

    // Retrieve the priority of the specified process
    int priority = getpriority(PRIO_PROCESS, pid);
    // Retrieve the scheduling policy of the specified process
    int policy = sched_getscheduler(pid);

    // Check if retrieving priority failed, which is indicated by errno
    if (priority == -1 && errno != 0) {
        perror("Error getting priority");
        return 1;
    }

    // Check if retrieving the scheduling policy failed
    if (policy == -1) {
        perror("Error getting scheduler");
        return 1;
    }

    // Output the process ID
    printf("Process ID: %d\n", pid);
    
    // Output the process priority
    printf("Process priority: %d\n", priority);
    
    // Print the scheduling policy in a readable format
    print_scheduler(policy);

    return 0;
}
