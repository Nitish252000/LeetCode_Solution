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
    // by Euclidean : The Euclidean algorithm is an efficient method to find the GCD of two numbers. It works on the principle that the GCD of two numbers remains the same if the greater number is replaced by the difference between the two numbers
    int gcd(int a, int b){
        if (a==0)return b;
        if (b==0)return a;
        if(a>b){
            return gcd(a-b,b);
        }
        return gcd(a,b-a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL)return head;
        ListNode* temp = head;
        ListNode* curr;
        while(temp->next!=NULL){
            int out=gcd(temp->val,temp->next->val);
            ListNode* node = new ListNode(out);
            curr=temp->next;
            temp->next=node;
            node->next=curr;
            temp=temp->next->next;
        }
        return head;
    }
};
