class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);  // Convert num to string for easy manipulation
        int n=str.size();
        int nmax=num;   // Track the maximum number found
        // Try all possible swaps
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(str[i],str[j]);   // Swap digits at index i and j
                nmax = max(nmax,stoi(str));  // Update maxNum if the new number is larger
                swap(str[i],str[j]);      // Swap back to restore the original string
            }
        }
        return nmax;    / Return the largest number after all possible swaps
    }
};
