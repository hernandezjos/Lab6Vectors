# Lab 6 – Vector Calculator

**Author:** Joey Hernandez  
**Language:** C

## (a) Program Description

This program is a simple vector calculator written in C. It uses conditional (`if/else`) logic to tokenize and interpret user input in a MATLAB-style format.

The calculator supports:
- Vector addition
- Vector subtraction
- Scalar multiplication
- Storage of up to 10 uniquely named vectors

## (b) Compilation Instructions

To compile the program using GCC:

```bash
gcc l5interface.c l5vectors.c -o vectors
```

Alternatively, use the Makefile:

```bash
make clean
make
```

## (c) Running the Program

Run the compiled program using:

```bash
./vectors
```


Alternatively, use -h flag for a helper text of input formatting:

```bash
./vectors -h
```


Enter vector values using a simplified MATLAB-style format. The program stores vectors by name, allowing them to be referenced in later calculations.

The user can perform vector addition, subtraction, and scalar multiplication using previously stored vectors.

## (d) Input Format and Commands

The program accepts input in the following formats:
|---------------------|---------------------------------------------------------|
| Input               | Description                                             |
|---------------------|---------------------------------------------------------|
| `a = 1 2 3`         | Creates vector `a` with three components                |
| `a + b`             | Adds vectors `a` and `b`                                |
| `c = a - b`         | Subtracts `b` from `a` and stores the result in `c`     |
| `2 * a`             | Multiplies vector `a` by scalar 2                       |
| `b = a * 2`         | Multiplies vector `c` by 2 and stores the result in `d` | 
| `a`                 | Displays the stored vector `a`                          |
|---------------------|---------------------------------------------------------|
| `list`              | Displays all stored vectors                             |
| `clear`             | Clears the vector storage                               |
| `quit`              | Exits the program                                       |
|---------------------|---------------------------------------------------------|

## (e) Memory Management

The program stores up to 10 vectors in memory.

**TODO:** Describe how memory is dynamically allocated in Vector lab dynamic memory update.