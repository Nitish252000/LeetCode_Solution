 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool reverseOrder= false;
        while(!q.empty()){
            int s = q.size();
            vector<int>store;
            for(int i=0; i<s; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
                store.push_back(temp->val);
            }
            if (reverseOrder)
                reverse(store.begin(), store.end());
            reverseOrder = !reverseOrder;
            ans.push_back(store);
        }
        return ans;
}
