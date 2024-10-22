/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // Problem asks for the level with the maximum sum in case of ties where
        // multiple levels have the same sum.In such cases, we should return the
        // smallest level with the maximum sum. in that case this will give error

        /*if (!root) return 0;  // Edge case: if root is null
        priority_queue<pair<int,int>> pq;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while (!q.empty()) {
            long size = q.size();
            long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* ele = q.front();
                q.pop();
                sum = sum + ele->val;
                // Push left and right children if they exist
                if (ele->left)
                    q.push(ele->left);
                if (ele->right)
                    q.push(ele->right);
            }
            pq.push(make_pair(sum,level));
            level++;
        }
        // The level with the maximum sum will be at the top of the priority
        queue return pq.top().second;*/

        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        int maxSum=INT_MIN;
        int maxlevel=1;
        while (!q.empty()) {
            long size = q.size();
            long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* ele = q.front();
                q.pop();
                sum = sum + ele->val;
                // Push left and right children if they exist
                if (ele->left)
                    q.push(ele->left);
                if (ele->right)
                    q.push(ele->right);
            }
            if(sum>maxSum){
                maxSum=sum;
                maxlevel=level;
            }
            level++;
        }
        return maxlevel;
    }
};
