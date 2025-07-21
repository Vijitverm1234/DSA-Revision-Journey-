# Data Structures and Algorithms (DSA) Guide in C++

This repository provides a comprehensive guide to essential Data Structures and Algorithms (DSA) concepts in C++, including tricks, time/space complexities, methods, and approaches. It is designed for quick reference and practical application in coding interviews and competitive programming.

## Table of Contents
- [Arrays](#arrays)
- [Linked Lists](#linked-lists)
- [Stacks and Queues](#stacks-and-queues)
- [Trees](#trees)
- [Graphs](#graphs)
- [Sorting Algorithms](#sorting-algorithms)
- [Searching Algorithms](#searching-algorithms)
- [Dynamic Programming](#dynamic-programming)
- [Tricks and Tips](#tricks-and-tips)

---

## Arrays
**Definition**: A contiguous collection of elements, accessible by index.

### Key Operations
- **Access**: O(1)
- **Insertion/Deletion**:
  - At end: O(1)
  - At beginning/middle: O(n) due to shifting
- **Search** (unsorted): O(n)
- **Search** (sorted): O(log n) with binary search

### Tricks
- **Two-Pointer Technique**: Use for problems like finding pairs with a given sum or removing duplicates.
  - Example: Find two numbers summing to target in a sorted array:
    ```cpp
    #include <vector>
    std::vector<int> twoSum(std::vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            if (arr[left] + arr[right] == target) {
                return {left, right};
            } else if (arr[left] + arr[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
    ```
- **Sliding Window**: Efficient for subarray problems.
  - Example: Maximum sum subarray of size k:
    ```cpp
    #include <vector>
    int maxSumSubarray(std::vector<int>& arr, int k) {
        int windowSum = 0, maxSum = 0;
        for (int i = 0; i < k; i++) windowSum += arr[i];
        maxSum = windowSum;
        for (int i = k; i < arr.size(); i++) {
            windowSum = windowSum - arr[i - k] + arr[i];
            maxSum = std::max(maxSum, windowSum);
        }
        return maxSum;
    }
    ```

### Approach
- Use `std::vector` for dynamic sizing and random access.
- For frequent insertions/deletions, consider linked lists.

---

## Linked Lists
**Definition**: A sequence of nodes, each containing data and a pointer to the next node.

### Key Operations
- **Access**: O(n)
- **Insertion/Deletion** (with pointer to node): O(1)
- **Search**: O(n)

### Tricks
- **Fast and Slow Pointers**: Detect cycles or find the middle.
  - Example: Cycle detection (Floyd’s Tortoise and Hare):
    ```cpp
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
    ```
- **Reverse a Linked List**: Iterative approach.
  - Example:
    ```cpp
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ```

### Approach
- Use for dynamic data with frequent insertions/deletions.
- Manage memory carefully (use `std::unique_ptr` for safety).

---

## Stacks and Queues
**Stacks**: LIFO (Last In, First Out)
- **Operations**: Push/Pop (O(1)) using `std::stack`.
- **Use Case**: Expression parsing, backtracking.
- **Trick**: Use for problems like valid parentheses.
  - Example:
    ```cpp
    #include <stack>
    #include <string>
    bool isValid(std::string s) {
        std::stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (!st.empty() && 
                       ((c == ')' && st.top() == '(') || 
                        (c == '}' && st.top() == '{') || 
                        (c == ']' && st.top() == '['))) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
    ```

**Queues**: FIFO (First In, First Out)
- **Operations**: Enqueue/Dequeue (O(1)) using `std::queue` or `std::deque`.
- **Use Case**: BFS, task scheduling.
- **Trick**: Use `std::deque` for sliding window or double-ended queue.

---

## Trees
**Definition**: Hierarchical structure with nodes connected by edges.

### Key Operations
- **Traversal**: O(n) for preorder, inorder, postorder, level-order.
- **Search/Insert/Delete** (BST): O(h) where h is height (O(log n) for balanced, O(n) for skewed).

### Tricks
- **Binary Search Tree (BST)**: Use for ordered data.
- **Level-Order Traversal**: Use BFS with a queue.
  - Example:
    ```cpp
    #include <queue>
    #include <vector>
    struct TreeNode {
        int val;
        TreeNode *left, *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
    ```

### Approach
- Use recursion for tree problems but optimize with iteration for large trees.
- Balance BSTs (e.g., AVL, Red-Black) for O(log n) operations.

---

## Graphs
**Definition**: Collection of nodes (vertices) connected by edges.

### Key Operations
- **Traversal**:
  - DFS: O(V + E) using recursion or stack.
  - BFS: O(V + E) using queue.
- **Shortest Path**:
  - Dijkstra’s: O((V + E) log V) with priority queue.
  - Bellman-Ford: O(V * E) for negative weights.

### Tricks
- **Adjacency List**: Preferred for sparse graphs (O(V + E) space).
- **Union-Find**: Efficient for detecting cycles or connected components.
  - Example:
    ```cpp
    #include <vector>
    class UnionFind {
        std::vector<int> parent, rank;
    public:
        UnionFind(int size) : parent(size), rank(size, 0) {
            for (int i = 0; i < size; i++) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unionSet(int x, int y) {
            parent[find(x)] = find(y);
        }
        bool connected(int x, int y) {
            return find(x) == find(y);
        }
    };
    ```

### Approach
- Choose BFS for shortest path in unweighted graphs.
- Use DFS for detecting cycles or connected components.

---

## Sorting Algorithms
| Algorithm       | Time Complexity (Best/Avg/Worst) | Space Complexity | Stable |
|-----------------|----------------------------------|------------------|--------|
| Bubble Sort     | O(n)/O(n²)/O(n²)                | O(1)             | Yes    |
| Quick Sort      | O(n log n)/O(n log n)/O(n²)     | O(log n)         | No     |
| Merge Sort      | O(n log n)/O(n log n)/O(n log n)| O(n)             | Yes    |
| Heap Sort       | O(n log n)/O(n log n)/O(n log n)| O(1)             | No     |

### Tricks
- **Quick Sort Pivot**: Choose random or median-of-three pivot to avoid O(n²) worst case.
  - Example:
    ```cpp
    #include <vector>
    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            अगर (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    ```

---

## Searching Algorithms
- **Linear Search**: O(n), simple but inefficient.
- **Binary Search**: O(log n) for sorted arrays.
  - Example:
    ```cpp
    #include <vector>
    int binarySearch(std::vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    ```

### Tricks
- Use binary search for monotonic functions or sorted data.
- For unsorted data with frequent searches, preprocess with sorting or use `std::unordered_map` (O(1) average).

---

## Dynamic Programming
**Definition**: Solve problems by breaking them into overlapping subproblems and storing results.

### Key Concepts
- **Memoization**: Top-down, recursive with caching.
- **Tabulation**: Bottom-up, iterative with table.
- **Time Complexity**: Depends on subproblems (e.g., O(n) for Fibonacci, O(n²) for knapsack).
- **Space Complexity**: O(n) or O(1) with optimization.

### Example (Fibonacci with Tabulation):
```cpp
#include <vector>
long long fibonacci(int n) {
    if (n <= 1) return n;
    std::vector<long long> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
```

### Tricks
- **State Reduction**: Reduce space by storing only necessary states.
  - Example (Space-optimized Fibonacci):
    ```cpp
    long long fibonacciOptimized(int n) {
        if (n <= 1) return n;
        long long prev = 0, curr = 1;
        for (int i = 2; i <= n; i++) {
            long long next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
    ```

---

## Tricks and Tips
- **Bit Manipulation**: Use for problems involving powers of 2, flags, or masking.
  - Example: Check if a number is a power of 2:
    ```cpp
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    ```
- **Prefix Sum**: Precompute sums for range queries.
  - Example:
    ```cpp
    #include <vector>
    std::vector<long long> prefixSum(std::vector<int>& arr) {
        std::vector<long long> prefix(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        return prefix;
    }
    ```
- **Greedy Approach**: Optimal for problems like activity selection or minimum spanning tree.
- **Divide and Conquer**: Use for problems like merge sort or binary search.
