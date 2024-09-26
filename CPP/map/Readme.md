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
