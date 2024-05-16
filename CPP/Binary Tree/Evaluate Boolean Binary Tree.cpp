bool evaluateTree(TreeNode* root) {
        if(root->left ==NULL && root->right == NULL){
            return root->val;
        }
        bool solveLeft = evaluateTree(root->left);
        bool solveRight = evaluateTree(root->right);
        bool res;
        if(root->val == 2){
            res = solveLeft||solveRight;
        }
        else{
            res = solveLeft && solveRight;
        }
        return res;
    }
