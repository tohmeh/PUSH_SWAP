# Push_swap

Push_swap is a sorting algorithm project that involves sorting a stack of integers (Stack A) using a set of specific operations and a second auxiliary stack (Stack B). The challenge is to sort the numbers with the fewest possible operations, optimizing for both speed and efficiency.

## Project Overview

The push_swap program takes a list of integers as input and outputs a sequence of operations that will sort Stack A in ascending order. The operations must use only Stack B as temporary storage. The project is designed to test your understanding of sorting algorithms, stack operations, and optimization techniques.

### Stacks and Operations

In this project, you manipulate two stacks:

- **Stack A**: The main stack that needs to be sorted.
- **Stack B**: An auxiliary stack used for temporary storage.

The operations allowed are:

- `sa`: Swap the first two elements at the top of Stack A.
- `sb`: Swap the first two elements at the top of Stack B.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the top element of Stack B onto Stack A.
- `pb`: Push the top element of Stack A onto Stack B.
- `ra`: Rotate Stack A upwards, moving the first element to the bottom.
- `rb`: Rotate Stack B upwards, moving the first element to the bottom.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Reverse rotate Stack A downwards, moving the last element to the top.
- `rrb`: Reverse rotate Stack B downwards, moving the last element to the top.
- `rrr`: Perform `rra` and `rrb` simultaneously.

### Algorithm Used: Radix Sort

To achieve an efficient sorting process, I implemented the **Radix Sort** algorithm. Radix Sort is particularly well-suited for sorting integers in this context because it processes the numbers digit by digit, allowing for a non-comparative sorting method that can handle a large number of elements efficiently.

### Objective

The objective is to sort Stack A in ascending order using the smallest possible number of operations. Since the problem can have multiple valid solutions, the project also involves finding and implementing the most efficient sorting strategy.

### Key Concepts

- **Radix Sort**: A non-comparative integer sorting algorithm that sorts numbers digit by digit, from the least significant digit to the most significant digit.
- **Stack Operations**: Efficient use of stack operations to achieve the sorted state with minimal steps.
- **Algorithm Optimization**: Finding ways to reduce the number of operations, such as recognizing patterns in the stack that can be optimized or skipped.

## Conclusion

Push_swap is a hands-on project that provides valuable experience in algorithm design and optimization, particularly in the context of constrained environments. It challenges you to think critically about how to manage resources (in this case, Stack B) and apply sorting techniques effectively, with the added complexity of using Radix Sort for optimized performance.
