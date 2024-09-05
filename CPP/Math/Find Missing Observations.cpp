class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        // Total number of n + m observations
        int totalObservations = n + m;
        // Calculate the total sum we need based on the mean
        int totalSum = mean * totalObservations;
        // Calculate the sum of the available rolls
        int currentSum = accumulate(rolls.begin(), rolls.end(), 0);
        // Calculate the sum needed for the missing rolls
        int missingSum = totalSum - currentSum;
        // Check if the missing sum can be distributed among the n missing rolls
        if (missingSum < n || missingSum > 6 * n) {
            // If it's not possible to distribute the missing sum among n rolls,
            // return an empty array
            return {};
        }
        
        int distributeMean = missingSum / n;
        int mod = missingSum % n;
    // Distribute the remaining mod elements by incrementing the first `mod` elements by 1
        vector<int> result(n, distributeMean);
        for (int i = 0; i < mod; i++) {
            result[i]++;
        }
        return result;
    }
};
