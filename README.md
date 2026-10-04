# Push Swap

An efficient algorithmic project from the 42 School curriculum focused on sorting data on a stack using a restricted set of instructions, with the lowest possible number of actions.

##  Overview

The goal of this project is to sort a random list of integers using two stacks (`stack_a` and `stack_b`) and a limited set of operations. The performance is evaluated strictly based on the **total number of operations** performed.

### Performance Benchmarks
- **3 numbers:** Max 3 operations.
- **5 numbers:** Max 12 operations.
- **100 numbers:** < 700 operations (5/5 points).
- **500 numbers:** < 5500 operations (5/5 points).

##  Features & Technical Highlights

- **Custom Algorithm:** Implemented a highly optimized sorting strategy utilizing Radix Sort to minimize instruction counts.
- **Data Structures:** Designed and manipulated **doubly linked lists** to represent stacks, ensuring O(1) time complexity for insertions and deletions.
- **Memory Management:** Written purely in **C** with rigorous allocation tracking (`malloc`/`free`). Fully checked and validated with **Valgrind** to guarantee **0 memory leaks**.
- **Input Validation:** Built a robust parsing engine handling edge cases such as duplicate arguments, non-integer inputs, and integer overflows/underflows (`INT_MAX`/`INT_MIN`).

## 🔄 The Instruction Set

The program output is a sequence of the following instructions:
- `sa` / `sb` / `ss`: Swap the first two elements of a stack.
- `pa` / `pb`: Push the top element from one stack to another.
- `ra` / `rb` / `rr`: Rotate a stack upward (first element becomes last).
- `rra` / `rrb` / `rrr`: Reverse rotate a stack downward (last element becomes first).

## 💻 Usage

### Compilation
Compile the project using the provided `Makefile`:
```bash
make
```

### Execution
Run the program by passing a list of integers as arguments. It will output the shortest sequence of instructions to sort them:
```bash
./push_swap 2 1 3 6 5 8
```

### Verification (With Checker)
You can pipe the instructions into a tester or the official checker to verify if the stack is correctly sorted:
```bash
ARG="4 67 3 87 23"; ./push_swap \(ARG \vert{} ./checker_OS\)ARG
# Output should be: OK
```

## 📊 Skills Earned

- Rigorous understanding of **algorithmic complexity** ($O(n^2)$ vs $O(n \log n)$ vs $O(n)$).
- Optimization of data structures for speed and efficiency.
- Proficient debugging and memory profiling in UNIX environments.
