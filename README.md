# Monty ByteCode Interpreter

Monty is a simple interpreter for Monty ByteCode files. Monty ByteCode files are a series of instructions, with each instruction on a new line. Monty interprets these instructions and executes them as operations on a stack. This project implements a stack (and queue) data structure using a doubly linked list.

## Prerequisites

- You need to have `gcc` and `make` installed on your system to compile the project.

## Getting Started

1. **Clone the repository:**

   ```bash
   git clone <repository-url>
   cd monty
   ```

2. **Compile the program:**

   ```bash
   make
   ```

3. **Run Monty:**

   ```bash
   ./monty <path/to/your/monty/file>
   ```

## Monty ByteCode Instructions

- **push <int>**: Pushes an element to the stack. `<int>` should be an integer.
- **pall**: Prints all the values on the stack, starting from the top of the stack.
- **pint**: Prints the value at the top of the stack.
- **pop**: Removes the top element of the stack.
- **swap**: Swaps the top two elements of the stack.
- **add**: Adds the top two elements of the stack.
- **nop**: Does nothing.

## Examples

**Example Monty ByteCode File:**

```plaintext
push 1
push 2
push 3
pall
pop
pall
```

**Output:**

```plaintext
3
2
1
2
1
```

## Error Handling

- If an error occurs during the execution of Monty, an error message will be displayed indicating the line number and the nature of the error.

## Note

- This project is for educational purposes and demonstrates the implementation of a Monty ByteCode interpreter using C programming language. Please note that this interpreter may not cover all edge cases and complexities of a full-fledged interpreter. It serves as an exercise in understanding stack data structures, parsing, and interpreting instructions from Monty ByteCode files in a simplified manner.

