# Experiment 10: Heap Data Structure – Finding Maximum and Minimum Marks

## Objective

To use heap data structures (max-heap and min-heap) to efficiently find the maximum and minimum marks obtained by students.

## Concept

A **heap** is a special tree-based data structure that satisfies the heap property:
- **Max-Heap:** The value of each node is greater than or equal to the values of its children. The largest element is at the root.
- **Min-Heap:** The value of each node is less than or equal to the values of its children. The smallest element is at the root.

Heaps are commonly implemented using arrays and are used in priority queues, sorting algorithms (heap sort), and for efficiently finding the largest or smallest elements.

## Implementation Details

- **Input:** The user enters the number of students and their marks.
- **Max-Heap:** Used to find the maximum marks.
- **Min-Heap:** Used to find the minimum marks.
- **STL Priority Queue:** In C++, `priority_queue<int>` is a max-heap by default. For a min-heap, `priority_queue<int, vector<int>, greater<int>>` is used.

## Code Flow

1. User enters the number of students and their marks.
2. All marks are inserted into both a max-heap and a min-heap.
3. The maximum mark is obtained from the top of the max-heap.
4. The minimum mark is obtained from the top of the min-heap.
5. Both values are displayed.

## Sample Output

```
Enter number of students: 5
Enter the marks obtained by students: 78 92 85 60 99
Maximum marks obtained: 99
Minimum marks obtained: 60
```

## Complexity Analysis

- **Insertion into Heap:** O(log n) per element.
- **Finding Max/Min:** O(1) (top of the heap).
- **Total Time:** O(n log n) for inserting all elements.

## Key Points to Explain

- **Heap Properties:** Max-heap for maximum, min-heap for minimum.
- **Priority Queue Usage:** Efficient way to implement heaps in C++.
- **Applications:** Scheduling, simulation, heap sort, and any scenario requiring quick access to largest/smallest elements.

## Viva Questions

- What is a heap? What are its types?
- How do you implement a min-heap and max-heap in C++?
- What is the time complexity for insertion and extraction in a heap?
- Where are heaps used in real-world applications?
- How does a priority queue relate to a heap?

---

**Prepared by:** Kasim Lohar  
**Roll No:** B-32

