class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_set<int>parent;
        unordered_set<int>child;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto i:desc){
            parent.insert(i[0]);
            parent.insert(i[1]);
            child.insert(i[1]);
            mp[i[0]].push_back({i[1],i[2]});
        }
        //Find the root node by checking which node is not present in children
        TreeNode* root = nullptr;
        for(auto it=parent.begin();it!=parent.end();it++){
            if(child.find(*it)==child.end()){
                root = new TreeNode(*it);
                break;
            }
        }
        if(root ==NULL)return NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            //if(mp.find(curr->val)!=mp.end()){
                for(auto i:mp[curr->val]){
                    TreeNode* childNode=new TreeNode(i.first);
                    if(i.second==1){
                        curr->left=childNode;
                    }else{
                        curr->right=childNode;
                    }
                    q.push(childNode);
                }
            //}
        }
        return root;
    }
};
