## stringstream
is a part of the <sstream> library that allows you to treat a string like a stream (like cin/cout) — so you can read from or write to a string like you do with files or standard input/output.

    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        string s = "geeks for geeks geeks contribution placements"; 
        stringstream ss(s);
        string word;
        int cnt = 0;
        
        while (ss >> word) {
            cnt++;
        }
        
        cout << cnt;
        return 0;
    }

**Note:**

    while(word<<ss)
This is incorrect syntax for reading from a stringstream. The correct way to extract words from a stringstream is:

    while (ss >> word)

### Common Uses:
| Task                          | Method | Description                                         |
|-------------------------------|--------|-----------------------------------------------------|
| Split a string into words     | `>>`   | Reads words separated by whitespace                 |
| Convert string to number      | `>>`   | Similar to `stoi()`, but more flexible              |
| Convert number to string      | `<<`   | Works like `to_string()`                            |
| Concatenate data into string  | `<<`   | Like using `+`, but easier for multiple data types  |
