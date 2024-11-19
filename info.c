/*
 * Name: Carla Sastre
 * Assignment: Lab 9 - System Calls
 * Section: CPE2600 - 2025S1
 */


#define _POSIX_C_SOURCE 200809L  // Enable POSIX features
#include <stdio.h>
#include <time.h>         // For clock_gettime and struct timespec
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>

int main() {
    struct timespec ts;
    struct utsname uname_data;
    struct sysinfo sys_info;

    // Current time in nanoseconds
    if (clock_gettime(CLOCK_REALTIME, &ts) == -1) {
        perror("clock_gettime failed");
        return 1;
    }
    printf("Current time: %ld nanoseconds\n", ts.tv_nsec);

    // Network and system information
    if (uname(&uname_data) == 0) {
        printf("Network name: %s\n", uname_data.nodename);
        printf("OS name: %s\n", uname_data.sysname);
        printf("OS release: %s\n", uname_data.release);
        printf("OS version: %s\n", uname_data.version);
        printf("Hardware type: %s\n", uname_data.machine);
    }

    // Number of CPUs and memory
    printf("Number of CPUs: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));

    // Total and free memory
    if (sysinfo(&sys_info) == 0) {
        printf("Total memory: %lu bytes\n", sys_info.totalram);
        printf("Free memory: %lu bytes\n", sys_info.freeram);
    }

    return 0;
}
