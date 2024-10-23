/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root)
            return false; // If the tree is empty
        // Queue for BFS traversal (stores the node and its parent value)
        queue<pair<TreeNode*, int>> bfsq;
        bfsq.push({root, -1}); // Start with root node, no parent (hence -1)
        // To store the depth and parent info of x and y
        unordered_map<int, pair<int, int>> nodeInfo;
        int depth = 0;
        while (!bfsq.empty()) {
            int size = bfsq.size();
            // Traverse the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = bfsq.front().first;
                int parent = bfsq.front().second;
                bfsq.pop();
                // If the node's value is x or y, store its depth and parent
                if (node->val == x || node->val == y) {
                    nodeInfo[node->val] = {depth, parent};
                }
                // Push the left and right children into the queue with the current node as parent
                if (node->left)
                    bfsq.push({node->left, node->val});
                if (node->right)
                    bfsq.push({node->right, node->val});
            }

            // If we have information for both x and y
            if (nodeInfo.count(x) && nodeInfo.count(y)) {
                // Check if x and y are at the same depth but have different parents
                return nodeInfo[x].first == nodeInfo[y].first && nodeInfo[x].second != nodeInfo[y].second;
            }
            depth++; // Increment depth for the next level
        }
        return false; // If x or y were not found
    }
};
