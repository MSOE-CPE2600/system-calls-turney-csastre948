/*
 * Name: Carla Sastre
 * Assignment: Lab 9 - System Calls
 * Section: CPE2600 - 2025S1
 */



#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>  // For mode_t
#include <time.h>
#include <pwd.h>

/**
 * Function to print the file type in a human-readable format.
 * @param mode - file mode obtained from stat structure
 */
void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) printf("File type: Regular file\n");
    else if (S_ISDIR(mode)) printf("File type: Directory\n");
    else printf("File type: Other\n");
}

/**
 * Function to print file permissions in a human-readable format.
 */
void print_permissions(mode_t mode) {
    printf("Permissions: %c%c%c%c%c%c%c%c%c\n",
           (mode & S_IRUSR) ? 'r' : '-',  // Owner read permission
           (mode & S_IWUSR) ? 'w' : '-',  // Owner write permission
           (mode & S_IXUSR) ? 'x' : '-',  // Owner execute permission
           (mode & S_IRGRP) ? 'r' : '-',  // Group read permission
           (mode & S_IWGRP) ? 'w' : '-',  // Group write permission
           (mode & S_IXGRP) ? 'x' : '-',  // Group execute permission
           (mode & S_IROTH) ? 'r' : '-',  // Others read permission
           (mode & S_IWOTH) ? 'w' : '-',  // Others write permission
           (mode & S_IXOTH) ? 'x' : '-'); // Others execute permission
}

int main(int argc, char *argv[]) {
    // Check if the filename is provided as a command-line argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;
    // Get file statistics; if it fails, print an error message and exit
    if (stat(argv[1], &file_stat) == -1) {
        perror("Error retrieving file information");
        return 1;
    }

    // Print file type (e.g., regular file, directory, etc.)
    print_file_type(file_stat.st_mode);

    // Print file permissions in a readable format (e.g., rwxr-xr-x)
    print_permissions(file_stat.st_mode);

    // Print owner ID of the file
    printf("Owner ID: %d\n", file_stat.st_uid);

    // Print file size in bytes
    printf("Size: %ld bytes\n", file_stat.st_size);

    // Print the last modified time of the file in a human-readable format
    printf("Last modified: %s", ctime(&file_stat.st_mtime));

    return 0;
}
