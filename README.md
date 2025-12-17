_This project has been created as part of the 42 curriculum by bokim, ayhammou_

# push_swap

## Description
- Push_swap is an algorithmic project focused on data sorting optimization. The challenge is to sort a stack of integers using only two stacks and a limited set of operations, while minimizing the total number of moves. This project explores algorithmic complexity in practice, requiring the implementation of multiple sorting strategies with different time complexities and an adaptive approach that selects the optimal strategy based on input characteristics.
- The project demonstrates that sorting efficiency depends not only on the algorithm chosen but also on the initial state of the data—highlighting the practical importance of Big-O notation and complexity analysis.

## Instructions 
### Compilation
```c
make			// Compile push_swap
make bonus		// Compile checker
make clean		// Remove object files
make fclean		// Remove object files and binaries
make re			// Recompile everything
```

### Usage
1. Basic usage (adaptive strategy by default):
```
./push_swap 3 2 1 5 4
```

2. Force a specific strategy:
```c
./push_swap --simple 5 4 3 2 1      // O(n²) algorithm
./push_swap --medium 8 3 1 6 2 9    // O(n√n) algorithm
./push_swap --complex 4 67 3 87 23  // O(n log n) algorithm
./push_swap --adaptive 2 1 3 6 5 8  // Adaptive (default)
```

3. Enable benchmark mode:
```c
./push_swap --bench --adaptive 5 4 3 2 1
```

4. Test with checker
```c
./push_swap 3 2 1 0 | ./checker_linux 3 2 1 0
```
5. Test with checker (bonus)
```c
./push_swap 3 2 1 0 | ./checker 3 2 1 0
```

### Available Operations
- `sa`/`sb`/`ss` : Swap first two elements of stack a / b / both
- `pa` / `pb` : Push top element from b to a / from a to b
- `ra` / `rb` / `rr` : Rotate stack a / b / both upward
- `rra` / `rrb` / `rrr` : Reverse rotate stack a / b / both downward

## Algorithm Implementations
### 1. Simple Algorithm - O(n²)

### 2. Medium Algorithm - O(n√n)

### 3. Complex Algorithm - O(n log n)

### 4. Adaptive Algorithm
- **Strategy** : Disorder-based strategy selection

**Disorder Calculation**
```
disorder = (number of inversions) / (total pairs)
```

**Strategy Selection**
- **Low disorder (< 0.2): O(n²)** - Optimized insertion with minimal moves
	- Uses intelligent rotation to place elements with minimal operations
	- Takes advantage of existing order

- **Medium disorder (0.2 ≤ disorder < 0.5): O(n√n)** - Chunk-based sorting
	- Balances between simplicity and efficiency
	- Good for partially sorted data

- **High disorder (≥ 0.5): O(n log n)** - Radix sort
	- Maximum efficiency for highly disordered data
	- Scales well with large inputs

## Performance Benchmarks
### Target Performance
**100 random numbers:**
- Pass : < 2000 operations
- Good : < 1500 operations
- Execellent : < 700 operations

**500 random numbers:**
- Pass : < 12000 operations
- Good : < 8000 operations
- Execellent : < 5500 operations

### Testing Performance
```c
// Test with 100 random numbers
./push_swap $(shuf -i 0-999 -n 100) | wc -l

// Test with 500 random numbers
./push_swap $(shuf -i 0-9999 -n 500) | wc -l

// Verify correctness
ARG=$(shuf -i 0-999 -n 100); ./push_swap $ARG | ./checker $ARG
```

## Group Contributions
- Both contributors participated in algorithm design discussions, debugging sessions, and performance optimization.

## Resources
- [Sorting Large Datasets with Limited Memory: The Chunked Merge Sort Approach](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81)
- [DSA Radix Sort](https://www.w3schools.com/dsa/dsa_algo_radixsort.php)
- [Radix Sort Algorithm](https://www.tutorialspoint.com/data_structures_algorithms/radix_sort_algorithm.htm)
- [Chunk-based Sorting Strategies](https://en.wikipedia.org/wiki/Bucket_sort)
- [Sorting Algorithms Visualized](https://visualgo.net/en/sorting)

## AI Usage
**Tasks where AI was used:**
- Debugging assistance: Identifying edge cases in rotation optimization
- Complexity analysis: Verifying time complexity calculations for chunk-based sorting
- Documentation: Structuring README and explaining algorithm choices