 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* move = head;
        ListNode *p = l1, *q = l2;
        int carry = 0;

        while(p!=NULL || q!=NULL){
            int x = (p!=NULL) ? p->val : 0;
            int y= (q!=NULL) ? q->val : 0 ;

            int sum =x+y+carry;

            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            move->next = newNode;
            move = move->next;

            if(p!=NULL)p=p->next;
            if(q!=NULL)q=q->next;
        }

        if(carry > 0){
            move->next = new ListNode (carry);
        }
        return head->next;
    }
