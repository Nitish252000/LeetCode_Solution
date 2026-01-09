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
    int maxDepth(Node* root) {
        int ans = 0;
        if(root==NULL)return 0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                Node* temp = q.front();
                q.pop();
                for(auto child:temp->children){
                    q.push(child);
                }
            }
            ans++;
        }
        return ans;
    }
};
