/*
 * Name: Carla Sastre
 * Assignment: Lab 9 - System Calls
 * Section: CPE2600 - 2025S1
 */



#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>    // For nice and nanosleep
#include <time.h>      // For nanosleep and struct timespec
#include <sys/resource.h>  // For nice function

int main() {
    // Reduce priority by 10
    nice(10);

    // Define the sleep duration in seconds and nanoseconds
    struct timespec ts = {1, 837272638};

    // Sleep for the specified duration
    if (nanosleep(&ts, NULL) == -1) {
        perror("nanosleep failed");
        return 1;
    }

    // Exit message
    printf("Goodbye!\n");
    return 0;
}
