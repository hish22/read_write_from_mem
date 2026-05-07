# Binary File I/O with C Structs

This repository contains a simple example of how to serialize and deserialize data in C using structs and binary file handling. It demonstrates how memory layouts (including padding) are written directly to disk and then reconstructed.

How it Works
Allocation: Memory is allocated for a videogame struct.

Serialization: The data is populated with hex values and written to a binary file (videogame.vg).

Deserialization: The file is read back into a new memory buffer.

Verification: The contents are printed to the console to verify data integrity.

## Quick Start
```bash
gcc main.c -o vgio
./vgio
```