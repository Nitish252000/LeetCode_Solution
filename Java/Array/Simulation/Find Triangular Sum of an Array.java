class Solution {
    public int triangularSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> temp = new ArrayList<>();

        // first row
        List<Integer> first = new ArrayList<>();
        for (int i : nums) {
            first.add(i);
        }
        temp.add(first);

        for (int i = 0; i < n - 1; i++) {
            List<Integer> curr = new ArrayList<>();
            for (int j = 0; j < temp.get(i).size() - 1; j++) {
                curr.add((temp.get(i).get(j) + temp.get(i).get(j + 1)) % 10);
            }
            temp.add(curr);
        }
        return temp.get(n - 1).get(0);
    }
}
