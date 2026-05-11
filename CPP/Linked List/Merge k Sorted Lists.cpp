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
    vector<int> nums;
    void helper(ListNode* list) {
        while (list != NULL) {
            nums.push_back(list->val);
            list = list->next;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto list : lists) {
            helper(list);
        }
        sort(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        for (auto& num : nums) {
            ListNode* newNode = new ListNode(num);
            temp->next = newNode;
            temp = newNode;
        }
        return dummy->next;
    }
};
