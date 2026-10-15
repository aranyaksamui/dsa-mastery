# My 14 week DSA Journey

### **1. Foundations & Algorithmic Mechanics**

* **Time & Space Complexity:** Big O Notation, Polynomial vs. Exponential time.
* **The C++ STL:** `std::vector`, `std::string`, `std::pair`, `auto`, and Iterators.
* **Divide and Conquer:** Binary Search ($O(\log N)$ logic) and splitting arrays.
* **Sorting Basics:** `std::sort` ($O(N \log N)$), custom comparators, and patience/frequency sorting.

### **2. Arrays, Strings & Hashing**

* **Two Pointers:** Opposite ends (Reversing, Palindromes) and Same direction (Fast/Slow for in-place array modification).
* **Sliding Window:** Fixed Size (Max Average) and Variable Size (Longest Substring Without Repeating Characters).
* **Hashing ($O(1)$ Lookups):** Frequency arrays, Hash Maps (`unordered_map`), Hash Sets (`unordered_set`), Anagram grouping, and One-to-One Bijections.

### **3. Linear Data Structures**

* **Linked Lists:** Memory pointers, Traversal, Reversing ($O(1)$ space), Merging using Dummy Nodes, Cycle Detection (Floyd’s Tortoise & Hare), and Deletion.
* **Stacks (LIFO):** Parentheses matching, String evaluation (Reverse Polish Notation), and the **Monotonic Stack** (Next Greater Element).
* **Queues (FIFO):** Data streaming, Adapter patterns (Queue using Stacks), and Level-Order traversals.
* **Advanced Design:** The Min-Stack ($O(1)$ history tracking).

### **4. Trees & Recursion**

* **Recursion:** The Call Stack, Base cases, state passing, and implicit memory.
* **Binary Trees:** DFS Traversals (Pre-order, In-order, Post-order) and BFS Traversal (Level-order using Queues).
* **Binary Search Trees (BST):** Left < Root < Right property, Insertion, Search, Validation (Min/Max ranges), Lowest Common Ancestor (LCA), Deletion (In-order Successor), and In-Order $K$-th Smallest extraction.

### **5. Heaps (Priority Queues)**

* **Binary Heaps:** Max-Heaps and Min-Heaps, $O(\log N)$ bubble-up/bubble-down mechanics.
* **Top K Elements:** Using Min-Heaps to filter streams of data.
* **Heap Simulation:** Last Stone Weight, Task Scheduler logic.
* **Advanced Heap Patterns:** Merging $K$ Sorted Lists, and the **Two Heaps Pattern** (Median from a Data Stream).

### **6. Backtracking (Decision Trees)**

* **Subsets:** The Include/Exclude pattern ($2^N$).
* **Permutations:** The In-place Swap pattern ($N!$).
* **Combinations:** Infinite supply recursion (Combination Sum).
* **Matrix DFS:** 4-way exploration, In-place visited marking (Word Search).
* **Hard Backtracking:** State Space Reduction and Diagonal Math (N-Queens).

### **7. Graphs & Disjoint Sets**

* **Representation:** Translating Edge Lists to Adjacency Lists.
* **Traversal:** BFS (Shortest unweighted path) and DFS (Connected Components/Number of Islands).
* **Directed Graphs:** 3-State arrays (White/Gray/Black) for Cycle Detection.
* **Topological Sort:** Kahn’s Algorithm (In-Degrees) for dependency resolution.
* **Union-Find (Disjoint Set):** Finding networks, Path Compression, and Cycle detection in undirected graphs.

### **8. Advanced Graph Algorithms**

* **Dijkstra’s Algorithm:** Single-Source Shortest Path (SSSP) using Min-Heaps.
* **Bellman-Ford Algorithm:** Handling Negative Weights and detecting Negative Cycles (DP on Graphs).
* **Prim’s Algorithm:** Minimum Spanning Tree (Greedy expansion).
* **Kruskal’s Algorithm:** Minimum Spanning Tree (Sorting + Union-Find).
* **Floyd-Warshall Algorithm:** All-Pairs Shortest Path ($O(V^3)$ Dynamic Programming).

### **9. Optimization: Greedy & Branch and Bound**

* **The Greedy Choice:** Sorting by ratios (Fractional Knapsack) and scheduling by deadlines (Job Sequencing).
* **Intervals:** Overlap merging (Sort by Start Time) and Activity Selection (Sort by End Time).
* **Array Greedy:** Max reach tracking and window scanning (Jump Game I & II).
* **Theory:** Branch and Bound (Pruning decision trees using greedy optimistic predictions).

### **10. Dynamic Programming (DP)**

* **1D DP:** Memoization (Top-Down) vs. Tabulation (Bottom-Up), State Transition Equations, and $O(1)$ Space Optimization (Climbing Stairs).
* **Knapsack Patterns:** Unbounded Knapsack (Coin Change) and 0/1 Knapsack (Subset Sum/2D to 1D optimization).
* **2D Grids:** Pathfinding and boundary base cases (Unique Paths).
* **Strings & Subsequences:** Longest Common Subsequence (LCS), Edit Distance (Levenshtein), and Longest Palindromic Subsequence (LPS).
* **Arrays:** Longest Increasing Subsequence (LIS) looking backwards.
* **Partition DP:** Matrix Chain Multiplication / Cutting points in $O(N^3)$ time.
