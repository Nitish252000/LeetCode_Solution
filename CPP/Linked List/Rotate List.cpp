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
    ListNode* rotateRight(ListNode* head, int k) {
        // --------- T.C = O(N), S.C = O(N) ------------------
        // if (head == NULL)
        //     return head;
        // vector<int> nums;
        // while (head != NULL) {
        //     nums.push_back(head->val);
        //     head = head->next;
        // }
        // k = k % nums.size();

        // vector<int> vec;
        // for (int i = nums.size() - k; i < nums.size(); i++) {
        //     vec.push_back(nums[i]);
        // }
        // for (size_t i = 0; i < nums.size() - k; i++) {
        //     vec.push_back(nums[i]);
        // }
        // ListNode* dummy = new ListNode(0);
        // ListNode* temp = dummy;
        // for (auto v : vec) {
        //     ListNode* newNode = new ListNode(v);
        //     temp->next = newNode;
        //     temp = newNode;
        // }
        // return dummy->next;

        if (head == NULL || head->next == NULL || k == 0) // empty || single node || k is zero
            return head;

        // find length
        int len = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        k = k % len;
        tail->next = head; // Circular

        ListNode* newhead;
        int move = len - k;
        int m = move - 1; // move just before new tail node
        ListNode* newtail = head;
        while (m--) {
            newtail = newtail->next;
        }
        newhead = newtail->next;
        newtail->next = NULL; // break;
        return newhead;
    }
};
