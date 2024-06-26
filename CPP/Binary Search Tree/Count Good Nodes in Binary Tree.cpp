int helper(TreeNode* root, int maxVal){
        if(root==NULL)return 0;
        int cnt =0;
        if(root->val>=maxVal){
            cnt++;
            maxVal= root->val;
        }
        cnt+=helper(root->left,maxVal);
        cnt+=helper(root->right,maxVal);
        return cnt;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }
