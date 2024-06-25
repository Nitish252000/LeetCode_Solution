void convert(TreeNode* root, int &sum){
        if(root==NULL)return;
        convert(root->right,sum);
        sum+=root->val;
        root->val= sum;
        convert(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root){
        int sum=0;
        convert(root,sum);
        return root;
    }



/*In a BST, an in-order traversal visits the nodes in non-decreasing order. By reversing the in-order traversal (i.e., visiting the right subtree, then the node, and finally the left subtree), we can accumulate the sum of all nodes greater than the current node.*/
