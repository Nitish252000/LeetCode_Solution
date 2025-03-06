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
