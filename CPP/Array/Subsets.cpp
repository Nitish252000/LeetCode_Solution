/*Iterative Generation:
    Start with an initial result containing an empty subset.
    For each element in the input array, iterate through the current subsets in the result.
    For each subset, create a new subset by adding the current element and add this new subset to the result.
    This method builds up the result iteratively by expanding each existing subset with each new element.
*/

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for (int i = 0; i < nums.size(); i++) {
            int n = result.size();
            for (int j = 0; j < n; j++) {
                vector<int> sub = result[j];
                sub.push_back(nums[i]);
                result.push_back(sub);
            }
        }
        return result;
}
