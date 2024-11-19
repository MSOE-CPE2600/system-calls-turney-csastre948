# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Executable names
EXECUTABLES = info pinfo pmod finfo

# Target to build all executables
all: $(EXECUTABLES)

# Compile info.c into the 'info' executable
info: info.c
	$(CC) $(CFLAGS) -o info info.c -lrt

# Compile pinfo.c into the 'pinfo' executable
pinfo: pinfo.c
	$(CC) $(CFLAGS) -o pinfo pinfo.c -lrt

# Compile pmod.c into the 'pmod' executable
pmod: pmod.c
	$(CC) $(CFLAGS) -o pmod pmod.c -lrt

# Compile finfo.c into the 'finfo' executable
finfo: finfo.c
	$(CC) $(CFLAGS) -o finfo finfo.c

# Clean up object files and executables
clean:
	rm -f $(EXECUTABLES)
