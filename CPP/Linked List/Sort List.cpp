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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
        if(l1!=NULL){
            temp->next=l1;
        }
        if(l2!=NULL){
            temp->next=l2;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        // -----T.C = O(NlogN) -- S.C = O(N) -------------
        // if (head == NULL)
        //     return NULL;
        // vector<int> nums;
        // while (head != NULL) {
        //     nums.push_back(head->val);
        //     head = head->next;
        // }
        // sort(nums.begin(), nums.end());
        // ListNode* dummy = new ListNode(0);
        // ListNode* temp = dummy; 
        // for (auto &num : nums) {
        //     ListNode* node = new ListNode(num);
        //     temp->next = node;
        //     temp = temp->next;
        // }
        // return dummy->next;
        if(head==NULL || head->next==NULL)return head;
        ListNode* mid = findMiddle(head); 
        ListNode* l = head;
        ListNode* r = mid->next;
        mid->next=NULL;
        l = sortList(l);
        r = sortList(r);

        return mergeSort(l,r);
    }
};
