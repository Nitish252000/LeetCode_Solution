/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxLevelSum(TreeNode root) {
        int level = 1;
        int maxi_level = Integer.MIN_VALUE;
        int max_sum = Integer.MIN_VALUE;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            int sz = q.size();
            int curr_level_sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode temp = q.poll();
                curr_level_sum += temp.val;
                if (temp.left != null)
                    q.offer(temp.left);

                if (temp.right != null)
                    q.offer(temp.right);
            }
            if (curr_level_sum > max_sum) {
                max_sum = curr_level_sum;
                maxi_level = level;
            }
            level++;
        }
        return maxi_level;
    }
}
