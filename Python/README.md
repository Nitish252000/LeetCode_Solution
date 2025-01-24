**Python Enumerate Function**
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
