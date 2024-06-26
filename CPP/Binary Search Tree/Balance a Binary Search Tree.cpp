void inorder(TreeNode* root, vector<int>&traversal){
        if(root==NULL)return;
        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right,traversal);
    }
    TreeNode* construct(vector<int>&traversal, int start, int end){
        //Base case: if start greater than end return NULL
        if(start>end)return NULL;
        int mid = start+(end-start)/2;
        TreeNode* node = new TreeNode(traversal[mid]);
        node->left=construct(traversal,start,mid-1);
        node->right=construct(traversal,mid+1,end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>traversal;
        inorder(root,traversal);
        int n = traversal.size();
        return construct(traversal, 0, n-1);
    }
