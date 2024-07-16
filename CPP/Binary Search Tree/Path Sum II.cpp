class Solution {
public:
    void helper(TreeNode* root, int sum, vector<int>path, vector<vector<int>>&paths){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL && root->val==sum){
            path.push_back(root->val);
            paths.push_back(path);
            return;
        }
        path.push_back(root->val);
        if(root->left!=NULL){
            helper(root->left,sum-root->val,path,paths);
        }
        if(root->right!=NULL){
            helper(root->right,sum-root->val,path,paths);
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>path;
        vector<vector<int>>paths;
        helper(root, sum, path, paths);
        return paths;
    }
};
