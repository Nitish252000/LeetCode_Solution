/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinSwaps(vector<int>&nums){
        int swp =0;
        vector<int>targ=nums;
        sort(targ.begin(),targ.end());
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=targ[i]){
                swp++;
                int curr=mp[targ[i]];
                mp[nums[i]]=curr;
                swap(nums[curr],nums[i]);
            }
        }
        return swp;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int tswap=0;
        while(!q.empty()){
            int s =q.size();
            vector<int>levelele;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                levelele.push_back(node->val);
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            tswap+=getMinSwaps(levelele);
        }
        return tswap;
    }
};
