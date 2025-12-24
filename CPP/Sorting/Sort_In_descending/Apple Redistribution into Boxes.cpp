class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        // Sort in descending order
        sort(capacity.begin(), capacity.end(),
             [](int a, int b) { return a > b; });
        int total_apple = accumulate(apple.begin(), apple.end(), 0);
        int boxes = 0;
        int curr_cap = 0;
        for (auto cap : capacity) {
            curr_cap += cap;
            boxes++;
            if (curr_cap >= total_apple) {
                return boxes;
            }
        }
        return boxes;
    }
};
