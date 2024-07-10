class Solution {
public:
    void reorderList(ListNode* head) {
        // vector<int>vec;
        // if(head==NULL)return;
        // while(head!=NULL){
        //     vec.push_back(head->val);
        //     head=head->next;
        // }
        // int start=0,end=vec.size()-1;
        // ListNode* dummy=new ListNode(0);
        // ListNode* node=dummy;
        // while(start<end){
        //     ListNode* newNode=new ListNode(vec[start]);
        //     node->next=newNode;
        //     node=node->next;
        //     ListNode* newNode1=new ListNode(vec[end]);
        //     node=node->next;
        //     start++;end--;
        // }
        // return dummy->next;
        if(head==NULL || head->next==NULL)return;
        vector<ListNode*>vec;
        ListNode* curr=head;
        while(curr!=NULL){
            vec.push_back(curr);
            curr=curr->next;
        }
        int start=0, end=vec.size()-1;
        while(start<end){
            vec[start]->next=vec[end]; // Link start node to end node
            start++;
            vec[end]->next=vec[start]; // Link end node to the new start node
            if(start==end)break;
            end--;
        }
        vec[start]->next=nullptr;
    }
};
