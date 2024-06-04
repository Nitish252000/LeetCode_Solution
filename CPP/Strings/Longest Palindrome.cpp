int longestPalindrome(string s) {
    unordered_map<char, int> mp;
    for (auto i : s) {
        mp[i]++;
    }
    int ans = 0;
    bool odd_found = false;
    for (auto i : mp) {
        if (i.second % 2 == 0) {
            ans += i.second;
        } else {
            ans += i.second - 1;  // Add the even part of the odd count
            odd_found = true;     // Mark that an odd character count was found
        }
    } 
    if (odd_found) {
        ans++;  // Add one to the result to account for a central character in the palindrome
    }  
    return ans;
}
