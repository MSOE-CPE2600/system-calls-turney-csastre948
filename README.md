# Lab 9 - System Calls

## Overview

This project is part of the CPE-2600 Systems Programming course and involves working with POSIX system calls on a Linux operating system. The purpose of this lab is to gain familiarity with commonly used system calls in the following categories:
- Information Maintenance
- Process Control
- File Management

### Programs

This project includes four programs:
1. **info.c** - Retrieves and displays system information.
2. **pinfo.c** - Displays process information for a specified or current process.
3. **pmod.c** - Modifies its own priority and pauses execution for a set amount of time.
4. **finfo.c** - Displays file information including type, permissions, owner, size, and last modification date.

### Files

- **info.c**: Program to display various system information.
- **pinfo.c**: Program to retrieve and display process information.
- **pmod.c**: Program that adjusts process priority and sleeps for a specified time.
- **finfo.c**: Program that displays detailed information about a specified file.
- **Makefile**: Makefile to compile the programs.
- **README.md**: Documentation for the project.

## Compilation

To compile all programs, run:

```bash
make
