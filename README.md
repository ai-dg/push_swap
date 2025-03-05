# 🔄 push_swap - Sorting with the Fewest Moves

<img src="https://github.com/user-attachments/assets/c2f35a76-a08f-4da6-81ff-39f8e7fc7e83" width="500">

![Score](https://img.shields.io/badge/Score-100%25-brightgreen)  
📌 **42 School - Algorithmic & Sorting Project**  

## 📝 Description
The **push_swap** project is about implementing an efficient sorting algorithm using a limited set of stack operations.  
The objective is to **sort a stack of integers using the fewest possible moves**.

This project helped develop skills in **algorithm design, data structures, and complexity optimization**.

## 🔥 Key Features
✅ **Implements an optimized sorting algorithm**  
✅ **Calculates the number of moves for each operation and selects the most efficient one**  
✅ **Uses a combination of stack operations (`sa`, `pb`, `ra`, `rr`, etc.)**  
✅ **Handles edge cases like duplicates, invalid inputs, and sorted inputs efficiently**  

## 🏆 Result: **100% Score**
The project was successfully validated with a **100% score**, meeting all the evaluation benchmarks. 🎉

## 📁 Files
- `push_swap.h` → Contains function prototypes and required macros  
- `push_swap.c` → Main function to handle input and call sorting operations  
- `stack_operations.c` → Contains stack manipulation functions  
- `sorting_algorithm.c` → Implements the sorting logic and optimization strategy  
- `Makefile` → Automates compilation (`all`, `clean`, `fclean`, `re`, `bonus`)  

## ⚙️ Implemented Operations
### 🔹 **Stack Operations**
| Command | Description |
|---------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the first element of B to A |
| `pb` | Push the first element of A to B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | Perform `rra` and `rrb` simultaneously |

## 🏹 **Sorting Algorithm & Optimization**
My **push_swap** implementation **calculates the number of moves needed for each operation and selects the best one** to **minimize the total number of operations**.

The algorithm adapts based on the **size of the stack**:
- **Small sets (≤5 elements):** Uses simple sorting logic with direct swaps and rotations.
- **Medium sets (≤100 elements):** Implements an optimized **divide-and-conquer approach**.
- **Large sets (500+ elements):** Uses an **advanced chunk-based sorting method** to reduce complexity.

## 🚀 Compilation & Usage
### 🛠 **Compile the Program**
```sh
make
```

▶️ Run push_swap
To sort a list of numbers:
```sh
./push_swap 4 67 3 87 23
```

▶️ Run push_swap with the checker

Add the permissions:
```sh
chmod 755 ./checker_linux
```

To verify if the sorting sequence is correct:
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

If the output is OK, the sorting is correct.
If the output is KO, the sorting sequence is incorrect.

### 🏆 Benchmark Requirements
To validate this project, the sorting algorithm must perform within strict operation limits:

- 100 numbers → ≤ 700 operations
- 500 numbers → ≤ 5500 operations

These benchmarks ensure the sorting algorithm is efficient and competitive.

## 📜 License

This project was completed as part of the **42 School** curriculum.  
It is intended for **academic purposes only** and follows the evaluation requirements set by 42.  

Unauthorized public sharing or direct copying for **grading purposes** is discouraged.  
If you wish to use or study this code, please ensure it complies with **your school's policies**.
