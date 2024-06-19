int characterReplacement(string s, int k) {
        int left = 0; // Left Pointer of the window  
        int maxl = 0; // Maximum length of the valid window
        int maxf = 0; // Maximun frquency of a single character in the current window
        vector<int> freq(26, 0);  // Frquency array for characters
        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxf = max(maxf, freq[s[right] - 'A']);
            // Check if the current window is valid
            if (right - left + 1 - maxf > k) {
                // If not valid, shrink the window from the left
                freq[s[left] - 'A']--;
                left++;
            }
            // Update the maximum length of the valid window
            maxl = max(maxl, right - left + 1);
        }
        return maxl;
    }
