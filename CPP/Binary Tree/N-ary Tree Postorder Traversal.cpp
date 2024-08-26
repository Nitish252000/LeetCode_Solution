/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traverse (Node* currNode, vector<int>&ans){
        if(currNode == NULL)return;
        //traverse of children node
        for(auto child:currNode->children){
            traverse(child, ans);
        }
        ans.push_back(currNode->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        if (root==NULL)return ans;
        traverse(root,ans);
        return ans;
    }
};
