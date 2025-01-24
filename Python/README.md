# **Python Enumerate Function**
The enumerate() function in Python is used to add a counter to an iterable, such as a list, tuple, or string. It returns an enumerate object which is an iterator that produces a sequence of tuples. Each tuple contains an index and the corresponding value from the iterable.

  Here are some key points about the enumerate() function:

  **Syntax:** The basic syntax is enumerate(iterable, start=0), where iterable is the sequence you want to iterate over, and start is the index number you want to start from (default is 0).
  
  **Usage:** The function is commonly used in loops to get both the index and the value of each element in the iterable. For example:

  
    items = ['apple', 'banana', 'cherry']
    for i, item in enumerate(items):
      print(f"Index {i}: {item}")

    This will output:
    Index 0: apple
    Index 1: banana
    Index 2: cherry
----------------------------------------------------------------------
# **Implement a Queue in Python**
Queue can be implemented by the following ways:
- list
- collections.deque
- queue.Queue
## Implemention using list

      queue = []
      queue.append('a')
      queue.append('b')
      queue.append('c')
      print("Initial queue")
      print(queue)
      print("\nElements dequeued from queue")
      print(queue.pop(0))
      print(queue.pop(0))
      print(queue.pop(0))
      print("\nQueue after removing elements")
      print(queue)
## Implementation using collections.deque

    from collections import deque
    q = deque()
    q.append('a')
    q.append('b')
    q.append('c')
    print("Initial queue")
    print(q)
    print("\nElements dequeued from the queue")
    print(q.popleft())
    print(q.popleft())
    print(q.popleft())
    
    print("\nQueue after removing elements")
    print(q)

## Implementation using queue.Queue

    from queue import Queue
    q = Queue(maxsize = 3)
    print(q.qsize()) 
    q.put('a')
    q.put('b')
    q.put('c')
    print("\nFull: ", q.full()) 
    print("\nElements dequeued from the queue")
    print(q.get())
    print(q.get())
    print(q.get())
    print("\nEmpty: ", q.empty())
    q.put(1)
    print("\nEmpty: ", q.empty()) 
    print("Full: ", q.full())
