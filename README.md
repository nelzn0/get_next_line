*This project has been created as part of the 42 curriculum by nda-roch.*

---

## Description

**get_next_line** is a project at 42 that challenges students to write a function that reads a line from a file descriptor. The goal is to design a function that, when called in a loop, allows the reading of an entire text file one line at a time until the end of the file (EOF).

The project introduces key concepts in C programming:

* **Static Variables**: To "remember" data between successive function calls.
* **Buffer Management**: Handling data chunks of arbitrary sizes (defined by `BUFFER_SIZE`).
* **Memory Management**: Efficiently allocating and freeing memory to prevent leaks and handle massive files.
* **File Descriptors**: Interacting with the system's I/O to read from files or standard input.

---

## Instructions

### Compilation

The function is designed to be integrated into other projects. To compile the code, you must define a `BUFFER_SIZE`.

Example command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

```

### Execution

1. Include the header in your C file: `#include "get_next_line.h"`
2. Open a file descriptor using `open()`.
3. Call `get_next_line(fd)` in a loop.
4. **Crucial**: Ensure you `free()` the pointer returned by the function to avoid memory leaks.

---

## Algorithm Explanation

The algorithm follows a "Read-Store-Extract-Trim" logic to handle the uncertainty of where a line ends relative to the `BUFFER_SIZE`.

### 1. The Read Loop

The function reads from the file descriptor into a temporary buffer. This data is then joined to a **static variable** (the "stash"). The loop continues until a newline character (`\n`) is found in the stash or `read()` returns 0 (EOF).

### 2. Line Extraction

Once the stash contains at least one full line, the algorithm scans for the first `\n`. It allocates memory for this specific line (including the `\n` if present) and copies it to be returned to the user.

### 3. Stash Trimming

After the line is extracted, the "used" part of the string must be removed. The algorithm creates a new version of the stash containing only the characters that appeared *after* the newline. The old stash is freed, and the new one is saved for the next call.

### 4. Justification of Static Variables

A static variable is used because the `read()` function may pull more data than what is needed for a single line. Without a static pointer, that "extra" data would be lost between function calls. The static variable acts as a persistent cache that lives for the duration of the program's execution.

---

## Technical Choices

* **Efficiency ($O(n)$ optimization)**: To handle giant lines and avoid timeouts, the algorithm uses pointer arithmetic to find newlines and calculate lengths, minimizing the number of times `ft_strlen` or `ft_strchr` are called on the same string.
* **Bonus Implementation**: The bonus version uses an array of static pointers (`static char *stash[OPEN_MAX]`) to manage multiple file descriptors simultaneously without losing the state of one file when reading from another.

---

## Resources

* [Unix System Calls - Read](https://man7.org/linux/man-pages/man2/read.2.html)
* [Static Variables in C (GeeksforGeeks)](https://www.geeksforgeeks.org/static-variables-in-c/)
* [Understanding File Descriptors](https://en.wikipedia.org/wiki/File_descriptor)

### Use of AI

AI was used in this project as a collaborative peer for the following tasks:

* **Debugging**: Identifying the cause of `Segmentation Faults` related to `NULL` returns from `malloc` (NULL_CHECK tests).
* **Optimization**: Analyzing time complexity to resolve `Timeout` issues in "Giant Line" test cases.
* **Refactoring**: Guidance on improving code readability and standardizing variable types (converting `int` to `size_t` for safety).
* **Documentation**: Assistance in structuring this `README.md` to meet 42 curriculum requirements.
