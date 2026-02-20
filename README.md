# push_swap

A program that sorts a stack of integers using the fewest possible moves, with only
a second auxiliary stack and a fixed set of operations allowed.

## Features

- Sorts up to 500 integers using a binary radix sort approach
- Uses a dedicated fast path for small inputs (2 to 5 elements)
- Validates input for duplicates, non-integers, and out-of-range values
- Accepts numbers as separate arguments or as a single quoted string
- Outputs only the sequence of operations needed, nothing else

## Getting Started

```sh
make
./program/push_swap 3 1 4 1 5 9 2 6
```

Pass numbers as arguments or as a single quoted string:

```sh
./program/push_swap "3 1 4 1 5 9 2 6"
```

To clean build artifacts:

```sh
make fclean
```

## Project Structure

```
PUSH_SWAP/
├── src/          # Sorting logic, stack operations, input validation
├── include/      # Header file
├── LIBFT/        # Utility library (string, memory, printf, get_next_line)
└── program/      # Compiled binary output
```
