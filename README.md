# College Everyday Codes

Programs I wrote during my Diploma and B.Tech in Computer Science, kept as a reference for data structures, algorithms and basic networking.

## Contents

**`Code/C/Old/`: data structures and algorithms in C**
- Sorting: bubble, insertion, selection, merge, quick, heap
- Searching: linear, binary, closed hashing
- Linked lists: singly, circular, reversal, polynomial addition and multiplication
- Stacks and queues: array and linked-list versions, circular queue, deque, two stacks in one array
- Trees and graphs: AVL tree, right-threaded binary tree, depth-first search
- Expression conversion: infix to postfix and prefix
- Operating systems: round-robin CPU scheduling, System V message queue send and receive
- Sparse matrices, recursion exercises

**`Code/C/Current/Server Client Computer Networks/`**: TCP client and server in C (Computer Networks lab)

**`Code/PythonCode/`**: introductory Python exercises (lists, tuples, dictionaries, matrices, strings, primes, HCF)

## Running

```bash
gcc Code/C/Old/QuickSort.c -o quicksort && ./quicksort
python Code/PythonCode/Palindrome.py
```

The networking programs use POSIX sockets, so build them on Linux, macOS or WSL.
