class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long size=q.size();
            long sum=0;
            for(int i=0;i<size;i++){
                TreeNode* ele=q.front();
                q.pop();
                sum=sum+ele->val;
                // Push left and right children if they exist
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
            pq.push(sum);
        }
        if (pq.size() < k) return -1;
        for (int i = 0; i < k - 1; i++) pq.pop();
        return pq.top();
    }
};
