class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // ListNode* node = head->next;
        // ListNode* merge=node;
        // while(merge!=NULL){
        //     int sum=0;
        //     while(merge->val!=0){
        //         sum=sum+merge->val;
        //         merge = merge->next;
        //     }
        //     node->val=sum;
        //     merge=merge->next;
        //     node->next=merge;
        //     node = node->next;

        // }
        // return head->next;
    //--------Another Approach---------------
        ListNode* newNode = new ListNode(0);
        ListNode* node = newNode;
        ListNode* curr = head->next;
        while(curr!=NULL){
            int sum=0;
            while(curr->val!=NULL){
                sum=sum+curr->val;
                curr=curr->next;
            }
            curr=curr->next;
            ListNode* temp = new ListNode(sum);
            node->next = temp;
            node=node->next;
        }
        ListNode* result=newNode->next;
        delete newNode;
        return result;
    }
};
