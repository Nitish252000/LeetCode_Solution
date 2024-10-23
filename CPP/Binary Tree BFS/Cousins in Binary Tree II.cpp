/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>bfsq;
        bfsq.push(root);
        vector<int>levelsum;
        while(!bfsq.empty()){
            int sum = 0;
            int size = bfsq.size();
            for(int i=0;i<size;i++){
                TreeNode* node= bfsq.front();
                bfsq.pop();
                sum+=node->val;
                if(node->left)bfsq.push(node->left);
                if(node->right)bfsq.push(node->right);
            }
            levelsum.push_back(sum);
        }
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        root->val=0;
        while(!q.empty()){
            int s= q.size();
            for(int i=0;i<s;i++){
                TreeNode* curr = q.front();
                q.pop();
                int siblingsum = 0;
                if(curr->left){
                    siblingsum+=curr->left->val;
                }
                if(curr->right){
                    siblingsum+=curr->right->val;
                }
                if(curr->left){
                    curr->left->val=levelsum[level]-siblingsum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val=levelsum[level]-siblingsum;
                    q.push(curr->right);
                }
            }
            level++;
        }
        return root;
    }
};
