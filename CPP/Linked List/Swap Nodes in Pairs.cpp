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
    ListNode* swapPairs(ListNode* head) {
        // ------------- Method 1: Using Vector-------------------
        // vector<int> vec;
        // if (head == NULL)
        //     return NULL;
        // while (head != NULL) {
        //     vec.push_back(head->val);
        //     head = head->next;
        // }
        // for (int i = 0; i < vec.size() - 1; i += 2) {
        //     swap(vec[i], vec[i + 1]);
        // }
        // ListNode* dummy = new ListNode(0);
        // ListNode* temp = dummy;
        // for (auto v : vec) {
        //     ListNode* Node = new ListNode(v);
        //     temp->next = Node;
        //     temp = temp->next;
        // }
        // return dummy->next;

        //------- Method 2: Iteratively swapping of adjacent Nodes
        //--------------------
        // if (head == NULL || head->next == NULL)
        //     return NULL;

        // ListNode* dummy = new ListNode(0);
        // ListNode* curr = dummy;
        // while (curr->next != NULL && curr->next->next != NULL) {
        //     ListNode* first = curr->next;
        //     ListNode* second = curr->next->next;
        //     curr->next = second;
        //     first->next = second->next;
        //     second->next = first;
        //     curr = curr->next->next;
        // }
        // return dummy->next;

        // ------Method 3: Using recursion - -----------
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* first = head;
        ListNode* second = head->next;

        ListNode* nextOfNode = swapPairs(second->next);
        second->next = first;
        first->next = nextOfNode;
        return second;
    }
};
