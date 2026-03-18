class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        // Case 1: if no moves
        if(k==0){
            return nums[0];
        }
        // Case 2: Only One Element
        if(n==1){
            if(k%2==1){
                return -1;
            }
            return nums[0];
        }
        // Case 3: General n >= 2 
        int maxi = -1;
        for(int i=0;i<min(k-1,n);i++){
            maxi=max(maxi,nums[i]);
        }
        // Option: take nums[k] if valid
        if(k < n){
            maxi = max(maxi, nums[k]);
        }

        return maxi;
    }
};



// Strategy:
//
// We have exactly k moves. In each move:
// 1) Remove top element
// 2) OR add back a previously removed element
//
// Goal: maximize the top element after exactly k moves
//
// Key Observations:
//
// 1. If k == 0 → no moves → answer is nums[0]
//
// 2. If n == 1:
//    - If k is odd → we remove the only element → pile becomes empty → return -1
//    - If k is even → we can remove and add back → return nums[0]
//
// 3. For n >= 2:
//    We have two choices:
//
//    (A) Take from removed elements:
//        - To reuse an element, we must remove it and add it back → needs 2 moves
//        - So we can remove at most (k-1) elements and use the last move to push back
//        - Hence we consider max element from nums[0] to nums[k-2]
//
//    (B) Do not push back anything:
//        - Remove k elements directly
//        - The new top becomes nums[k] (if k < n)
//
// 4. Final answer = max(
//        max element from first (k-1) elements,
//        nums[k] if k < n
//    )
//
// 5. If k >= n:
//    - We can remove all elements
//    - Only option is to rely on case (A)
//```
