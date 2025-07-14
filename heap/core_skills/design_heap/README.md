# Heap

A heap is a specialized, tree-based data structure.

It implements an abstract data type called the Priority Queue, but sometimes 'Heap' and 'Priority Queue' are used interchangeably.

We already learned that queues operate with a first-in-first-out basis but with a priority queue, the values are removed based on a specific priority. The element with the highest priority is removed first, regardless of the order in which it was added.

## Two types of heaps

**Min HeapMax Heap**

- Min Heap
- Max Heap

Min heaps have the smallest value at the root node. The smallest value has the highest priority to be removed.

Max heaps have the largest value at the root node. The largest value has the highest priority to be removed.

In this lesson, we will be focusing on min heaps, but the implementation is exactly the same for max heap, except you would prioritize the maximum value instead of the minimum.

## Heap Properties

**For a binary tree to qualify as a heap, it must satisfy the following properties:**

**1. Structure Property**

A binary heap is a binary tree that is a **complete binary tree**, where every single level of the tree is filled completely, except possibly the lowest level nodes, which are filled contiguously from left to right.

**2. Order Property**

The order property for a min-heap is that all of the descendent should be greater than their ancestors. In other words, if we have a root with value `y`, every node in the right and the left sub-tree should have values greater than or equal to `y`. This is a recursive property, similar to binary search trees.

**In a max-heap, every node in the right and the left sub-tree is smaller than or equal to `y`.**

> Unlike binary search trees, heaps may contain duplicate values.

**The following visual shows a binary heap.**

![image.png](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/14f4ac1b-f117-45e6-27e2-e7de3b0afa00/sharpen=1)

## Implementation

Binary heaps are drawn using a tree data structure but under the hood, they are implemented using arrays. Let's show how we can do this by using the given binary heap: `[14,19,16,21,26,19,68,65,30,null,null,null,null,null,null]`

We will take an array of size *n+1* where *n* is the number of nodes in our binary heap. This will make sense soon. We will visit our nodes in the same order as we visit nodes in breadth-first search - level by level, from left to right. We will insert these into our array in a contiguous fashion. However, we will start filling them from index `1` instead of `0`, for reasons we will discuss soon.

Once our array has been filled up, it would look like the following:

![image.png](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/2de1eb2d-7437-4cc9-4192-e9eaaf77d600/sharpen=1)

## One-based indexing

The reason why we start filling up our array from index `1` is because it helps us figure out the index at which a node's left child, right child, or the parent resides. Because binary heaps are complete binary trees, no space is required for pointers. Instead, a node's left child, right child and parent can be calculated using the following formulas, where *i* is the index of a given node.

**`leftChild` = 2∗*i***

**`rightChild` =2∗*i*+1**

**`parent` = *i*/2**

```cpp
// leftChild of i = heap[2 * i]
// rightChild of i = heap[(2 * i) + 1]
// parent of i = heap[i // 2]
```

**Suppose we wanted to find the children and parent of the node with value `19`. The following visual demonstrates how using the formulas helps us figure them out.**

The number above a node (in blue) is the corresponding index in the array of each node. It is important to note that these formulas only work when the tree is a complete binary tree and the array is filled contiguously from left to right.

We can also now appreciate why we start at index `1`. Suppose we wanted to find `14`'s left and right child and `14` was at `0`. Well, any number multiplied by a `0` is `0`, and would tell us that the left child resides at the `0`th index, which is of course not the case.

![image.png](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/d9af7215-abfe-4fbf-189c-3a82aeb98c00/sharpen=1)

**Below is the code implementation of a heap.**

```cpp
class Heap {
public:
    vector<int> heap_;

    Heap() {
        heap_.push_back(0);
    }
}
```
