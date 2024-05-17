TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL)return NULL;
        
    // Recursively call the function on left and right children
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
    // If the current node is a leaf and its value is equal to target, delete it
        if(root->left ==NULL && root->right == NULL && root->val == target){
            return NULL;
        }
        return root;
}
