# Map
- **std::map** in C++ is a sorted associative container that stores key-value pairs with unique keys.  
- It is implemented as a self-balancing binary search tree (typically a red-black tree), ensuring that operations like insertion, deletion, and lookup have logarithmic **time complexity O(log n)**.  
- Elements are automatically sorted by key using a comparison function (defaulting to std::less<Key>), which allows efficient range queries and ordered traversal. 

## Key Features:
- Unique Keys: Each key in a std::map must be unique. 
- Sorted Order: Elements are stored in ascending order based on keys. 
- Efficient Operations: insert(), erase(), find(), and count() operate in O(log n) time.
- operator[] and at() provide fast access with automatic insertion if the key does not exist.
- Member Functions: insert(), erase(), find(), count(), at(), begin(), end(), empty(), size(), clear(), swap(), lower_bound(), upper_bound(), equal_range(), and contains() (C++20). 

## When to Use std::map:
1. When you need sorted keys. 
2. When you frequently perform range queries (e.g., all keys between two values). 
3. When ordering and uniqueness are important.
   
## Comparison with std::unordered_map:
**Feature	             std::map	                                      std::unordered_map**\\
Order	                   Sorted by key	                                Unordered\\
Time Complexity	       O(log n) for most operations	                    O(1) average, O(n) worst case\\
Use Case	             When order matters or range queries needed	  When fastest average access is needed\\



















**Iterator on C++ Map**
In C++, a map is a container that stores key-value pairs, where each key is unique and maps to a specific value. There are several ways to iterate over the elements of a map, depending on your needs and the C++ version you’re using. Here are some common methods:

**Range-based for loop (C++11 and later):**

      std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};
      for (const auto& pair : myMap) {
          std::cout << pair.first << ": " << pair.second << std::endl;
      }

    This method is concise and easy to read. It iterates over the map’s elements, accessing each pair’s key (pair.first) and value (pair.second) using the auto keyword.

**Iterator-based loop:**

      std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};
      std::map<int, std::string>::iterator it = myMap.begin();
      while (it != myMap.end()) {
          std::cout << it->first << ": " << it->second << std::endl;
          ++it;
      }

    This method uses an iterator to traverse the map, accessing each pair’s key and value using the -> operator. Be sure to check for end() to avoid dereferencing an invalid iterator.

**Key points about count and find in C++ map**

In C++'s std::map, the "count" function checks if a specific key exists in the map and returns 1 if it does, while the "find" function returns an iterator pointing to the key-value pair associated with the given key if it exists in the map; if not, it returns an iterator pointing to the end of the map.

**Key Differences:**

      count() is useful when you need to check if a key exists in the map, but it only tells you whether the key is there or not (1 or 0).
      find() provides more detailed information by returning an iterator to the element, allowing access to both the key and the value.
