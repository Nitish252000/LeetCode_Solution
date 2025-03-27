class Solution {
    public int minimumIndex(List<Integer> nums) {
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        // Find Dominant number
        int dominant = -1, totalCount = 0;
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if (entry.getValue() > totalCount) {
                totalCount = entry.getValue();
                dominant = entry.getKey();
            }
        }

        int leftCount = 0, rightCount = totalCount;
        // Iterate to find the minimum valid split index
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums.get(i) == dominant) {
                leftCount++;
                rightCount--;
            }
            // The dominant element should be present more than half the size of the left subarray
            // check if dominant is dominant in both halves
            if (leftCount * 2 > i + 1 && 2 * rightCount > (nums.size()) - i - 1)
                return i;
        }
        return -1;
    }
}
