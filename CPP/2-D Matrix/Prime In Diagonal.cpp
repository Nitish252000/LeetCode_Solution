class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int rz = nums.size();
        int cz = nums[0].size();

        vector<int> dig;

        // diagonal : left to right
        for (int i = 0; i < rz; i++) {
            // for(int j=0;j<cz;j++){
            //     if(i==j){
            dig.push_back(nums[i][i]);
            //     }
            // }
        }
        // diagonal : right to left
        for (int i = 0; i < rz; i++) {
            for (int j = 0; j < cz; j++) {
                if (i + j ==rz - 1) {   // the cell is on the right-to-left diagonal
                    if (i != j) // skip if it's already counted (center element)
                        dig.push_back(nums[i][j]);
                }
            }
        }
        int maxi = 0;
        for (int num : dig) {
            if (isPrime(num)) {
                maxi = max(maxi, num);
            }
        }
        return maxi;
    }
};



// Right-to-left diagonal condition

// This diagonal runs from top-right to bottom-left:
// (0,2) → (1,1) → (2,0)

// Notice something:

// i + j = 2 for all of them   (since n = 3, n - 1 = 2)


// ✅ So the condition is:
// i + j == n - 1

// That’s what this line means:

// if (i + j == rz - 1)

// 🔄 Why if (i != j)

// In odd-sized matrices (like 3×3, 5×5, etc.), the center element (1,1) is on both diagonals.
// So we skip it once to avoid duplication:

// if (i != j)

// ✅ Combined meaning:
// if (i + j == rz - 1) {   // the cell is on the right-to-left diagonal
//     if (i != j)          // skip if it's already counted (center element)
//         dig.push_back(nums[i][j]);
// }
