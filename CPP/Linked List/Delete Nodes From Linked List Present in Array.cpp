/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st;
        for(auto i:nums){
            st.insert(i);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* newNode=dummy;
        vector<int>vec;
        if(head==NULL)return NULL;
        while(head!=NULL){
            if(st.count(head->val)==0){
                vec.push_back(head->val);
            }
            head=head->next;
        }
        for(int i=0;i<vec.size();i++){
            ListNode* node = new ListNode(vec[i]);
            newNode->next=node;
            newNode=newNode->next;
        }
        return dummy->next;
    }
};
