# Explanation with examples

Consider the following binary tree:
```
       1
      / \
     2   3
    / \   \
   4   5   6
```


## Step-by-Step Execution

### Initialization
- `ans` is initialized as an empty vector `[]`.
- A queue `q` is initialized and the root node `1` is pushed onto the queue: `q = [1]`.

### First Iteration of the While Loop
- `store` is initialized as an empty vector `[]`.
- `s` is set to the size of the queue, which is `1`.
- The for loop runs `1` time (since `s = 1`):
  - The node `1` is popped from the queue: `temp = 1`.
  - Its children `2` and `3` are pushed onto the queue: `q = [2, 3]`.
  - The value `1` is added to `store`: `store = [1]`.
- The `store` vector `[1]` is added to `ans`: `ans = [[1]]`.

### Second Iteration of the While Loop
- `store` is initialized as an empty vector `[]`.
- `s` is set to the size of the queue, which is `2`.
- The for loop runs `2` times (since `s = 2`):
  - The node `2` is popped from the queue: `temp = 2`.
  - Its children `4` and `5` are pushed onto the queue: `q = [3, 4, 5]`.
  - The value `2` is added to `store`: `store = [2]`.
  - The node `3` is popped from the queue: `temp = 3`.
  - Its right child `6` is pushed onto the queue: `q = [4, 5, 6]`.
  - The value `3` is added to `store`: `store = [2, 3]`.
- The `store` vector `[2, 3]` is added to `ans`: `ans = [[1], [2, 3]]`.

### Third Iteration of the While Loop
- `store` is initialized as an empty vector `[]`.
- `s` is set to the size of the queue, which is `3`.
- The for loop runs `3` times (since `s = 3`):
  - The node `4` is popped from the queue: `temp = 4`.
  - It has no children, so nothing is added to the queue: `q = [5, 6]`.
  - The value `4` is added to `store`: `store = [4]`.
  - The node `5` is popped from the queue: `temp = 5`.
  - It has no children, so nothing is added to the queue: `q = [6]`.
  - The value `5` is added to `store`: `store = [4, 5]`.
  - The node `6` is popped from the queue: `temp = 6`.
  - It has no children, so nothing is added to the queue: `q = []`.
  - The value `6` is added to `store`: `store = [4, 5, 6]`.
- The `store` vector `[4, 5, 6]` is added to `ans`: `ans = [[1], [2, 3], [4, 5, 6]]`.

### End of While Loop
- The queue `q` is now empty, so the while loop terminates.
- The function returns the `ans` vector: `[[1], [2, 3], [4, 5, 6]]`.

## Summary

The while loop processes the tree level by level. In each iteration of the while loop, it processes all nodes at the current level (determined by the size of the queue at the beginning of the loop). The for loop inside the while loop handles all nodes at the current level, and their children are added to the queue for the next level. This ensures that each level of the tree is processed and added to the result in order.

By following this method, the function achieves a level order traversal of the tree, producing the result `[[1], [2, 3], [4, 5, 6]]` for the given example tree.

