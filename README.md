# Data Structures and Algorithms

These are my assignments for the university course *Data Structures and Algorithms*, written in C.

## Projects

| # | Project | Description |
|---|---------|-------------|
| 01 | [String functions](01-string-functions) | My own implementations of `string.h` functions (`strlen`, `strcpy`, `strcmp`, `strcat`, `strstr`) and a string reverse function |
| 02 | [Arrays and structs](02-arrays-and-structs) | Dynamic arrays (subarrays, filtering, splitting) and a polygon built from point structs |
| 03 | [STL files](03-stl-files) | Reading a 3D model from a binary STL file and writing it back as a binary and a text STL file |
| 04 | [Time complexity](04-time-complexity) | Measuring how long set intersection takes with linear search compared to sorting with `qsort` and searching with `bsearch` |
| 05 | [Sorting algorithms](05-sorting-algorithms) | Selection sort, insertion sort, quicksort (with median-of-three pivot) and merge sort, with execution time measurements |
| 06 | [Linked list dictionary](06-linked-list-dictionary) | A sorted singly linked list that stores words and how many times each word appears |
| 07 | [Priority queue](07-priority-queue) | A priority queue implemented as a binary heap |
| 08 | [Binary search tree](08-binary-search-tree) | A binary search tree of words read from a text file, with tree height and saving and loading the tree to a file |
| 09 | [Hash table](09-hash-table) | A hash table with separate chaining, filled with words from a large text file and tested with different table sizes |
| 10 | [Wolf, sheep and cabbage](10-wolf-sheep-cabbage) | The river crossing puzzle, solved with recursion and with a queue |

## Running a project

Each folder is a standalone program that builds on Windows, Linux and macOS.

On Linux or macOS, compile all `.c` files in the folder with GCC or Clang:

```sh
cd 08-binary-search-tree
gcc *.c -o bst
./bst
```

On Windows, add the folder's `.c` and `.h` files to an empty Visual Studio C project. The STL files project already includes its Visual Studio solution (`03-stl-files/stl-files.sln`).

Run each program from inside its own folder so it can find its input files (`sample-binary.stl`, `liar.txt` and `big.txt`).

## What I learned

1. Define static and dynamic data structures and the standard algorithms that work with them (stacks, heaps, arrays, lists, trees, graphs, hash tables, sorting and searching algorithms, min-max algorithms)
2. Show the advantages and disadvantages of specific algorithms and data structures
3. Identify bugs in programs and recognize which basic data structure operations are needed
4. Create new solutions to programming problems or improve existing code with the algorithms I learned
5. Assess algorithms and data structures by the time and memory complexity of their basic operations
