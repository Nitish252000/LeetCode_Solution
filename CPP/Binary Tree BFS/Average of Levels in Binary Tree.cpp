vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long sum = 0;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                sum = sum + temp->val;
            }
            ans.push_back((double)(sum) / s);
        }
        return ans;
}
