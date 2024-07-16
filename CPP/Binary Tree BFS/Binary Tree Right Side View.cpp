vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;  // Initialize the result vector
    if (root == NULL)  // If the root is NULL, return the empty result vector
        return ans;
    
    queue<TreeNode*> q;  // Initialize the queue
    q.push(root);  // Push the root node to the queue
    
    while (!q.empty()) {  // Continue until the queue is empty
        int s = q.size();  // Get the number of nodes at the current level
        for (int i = 0; i < s; i++) {  // Iterate through all nodes at the current level
            TreeNode* temp = q.front();  // Get the front node in the queue
            q.pop();  // Remove the front node from the queue
            if (i == s - 1) {  // If it's the last node at this level
                ans.push_back(temp->val);  // Add it to the result vector
            }
            if (temp->left)  // If the left child exists
                q.push(temp->left);  // Push the left child to the queue
            if (temp->right)  // If the right child exists
                q.push(temp->right);  // Push the right child to the queue
        }
    }
    return ans;  // Return the result vector
}
