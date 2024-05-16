# Push_swap

## Description

The "Push_swap" project is a simple yet challenging algorithm project. The goal is to sort a stack of integers using a limited set of instructions with the fewest possible actions. This project requires the implementation of various algorithms to find the most efficient sorting solution.

## Getting Started

### Prerequisites

- CC
- Make
- Git

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/push_swap.git
    ```

2. Navigate to the project directory:
    ```bash
    cd push_swap
    ```

3. Compile the project:
    ```bash
    make
    ```

## Usage

### Running the Program

To run the program and sort a list of integers:
```bash
./push_swap 2 1 3 6 5 8
```
OR
```bash
./push_swap "2 1 3 6 5 8"
```

This command will output a sequence of instructions to sort the given integers.

### Example

Given the input:
```bash
./push_swap 2 1 3 6 5 8
```

The program might output:
```
sa
pb
pb
pb
sa
pa
pa
pa
```

### Handling Errors

If the input contains invalid integers or duplicates, the program will display an error message:
```bash
./push_swap 0 one 2 3
Error
```

## Implementation Details

### Overview

- **Stacks**: The project uses two stacks, `a` and `b`.
- **Instructions**: A set of operations to manipulate the stacks, including `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

### Rules

| Instruction | Description |
|-------------|-------------|
| `sa`        | Swap the first two elements of stack `a`. Do nothing if there is only one or no elements. |
| `sb`        | Swap the first two elements of stack `b`. Do nothing if there is only one or no elements. |
| `ss`        | Perform `sa` and `sb` simultaneously. |
| `pa`        | Push the top element of `b` onto `a`. Do nothing if `b` is empty. |
| `pb`        | Push the top element of `a` onto `b`. Do nothing if `a` is empty. |
| `ra`        | Rotate stack `a` upwards. The first element becomes the last one. |
| `rb`        | Rotate stack `b` upwards. The first element becomes the last one. |
| `rr`        | Perform `ra` and `rb` simultaneously. |
| `rra`       | Reverse rotate stack `a`. The last element becomes the first one. |
| `rrb`       | Reverse rotate stack `b`. The last element becomes the first one. |
| `rrr`       | Perform `rra` and `rrb` simultaneously. |

### Algorithm

The program implements the "mechanic turk" algorithm:

1. **Parsing Input**: The integers provided as arguments are parsed and stored in stack `a`.
2. **Calculate Costs**: For each number in stack `a`, the program calculates the total cost of rotating and pushing that number to the correct position in stack `b`.
3. **Push Cheapest Cost**: The number with the lowest cost is pushed to stack `b`.
4. **Repeat**: Steps 2 and 3 are repeated until stack `a` is empty.
5. **Final Sort**: Once stack `a` is empty, all elements are pushed back from stack `b` to stack `a`, resulting in a sorted stack `a`.

### Error Handling

- Arguments must be valid integers.
- Arguments must be within the range of an integer.
- No duplicates are allowed.

## Bonus Part

### The `checker` Program

In addition to the mandatory `push_swap` program, a `checker` program is implemented to verify the correctness of the sorting instructions.

#### Running the Checker

1. Compile the bonus part:
    ```bash
    make bonus
    ```

2. To check if the instructions correctly sort the stack:
    ```bash
    ./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
    ```

The `checker` program will output `OK` if the stack is sorted correctly, otherwise it will output `KO`.

### Handling Errors

The `checker` program will display `Error` for invalid inputs, including:
- Non-integer arguments
- Arguments out of integer range
- Duplicate values
- Invalid or incorrectly formatted instructions
