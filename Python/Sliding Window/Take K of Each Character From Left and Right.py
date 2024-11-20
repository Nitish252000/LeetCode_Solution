class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        mp = defaultdict(int)
        for i in s:
            mp[i] += 1
        if mp["a"] < k or mp["b"] < k or mp["c"] < k:
            return -1

        left = 0
        windowFreq = defaultdict(int)
        maxWindow = 0

        for right in range(len(s)):
            windowFreq[s[right]] += 1
            while left <= right and (mp["a"] - windowFreq["a"] < k or mp["b"] - windowFreq["b"] < k or mp["c"] - windowFreq["c"] < k):
                # Shrink the window from the left
                windowFreq[s[left]] -= 1
                left += 1

            # Update the maxWindow if the current window is larger
            maxWindow = max(maxWindow, right - left + 1)

        # Return the minimum number of characters to be taken
        return len(s) - maxWindow
