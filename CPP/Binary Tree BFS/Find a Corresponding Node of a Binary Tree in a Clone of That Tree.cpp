/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        queue<TreeNode*> org;
        queue<TreeNode*> clo;

        org.push(original);
        clo.push(cloned);
        while (!org.empty() || !clo.empty()) {
            TreeNode* node1 = org.front();
            org.pop();
            TreeNode* node2 = clo.front();
            clo.pop();
            if (node1 == target)
                return node2;
            if (node1->left)
                org.push(node1->left);
            if (node1->right)
                org.push(node1->right);
            if (node2->left)
                clo.push(node2->left);
            if (node2->right)
                clo.push(node2->right);
        }
        return NULL;
    }
};
