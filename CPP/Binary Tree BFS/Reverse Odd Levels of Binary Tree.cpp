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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level =0;
        while(!q.empty()){
            int s = q.size();
            vector<TreeNode*>levelNodes;
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                levelNodes.push_back(temp);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            if(level%2==1){
                int left=0;int right=levelNodes.size()-1;
                while(left<right){
                    int temp=levelNodes[left]->val;
                    levelNodes[left]->val=levelNodes[right]->val;
                    levelNodes[right]->val=temp;
                    left++;
                    right--;                    
                }
            }
            level++;
        }
        return root;
    }
};
