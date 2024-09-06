# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        st = set()    # Created a set `st` to store unique elements from the nums list.
        for i in nums:   # Iterated over each elements in 'nums' and add it to the set 'st'.
            st.add(i)
        li=list()       # Created an empty list 'li' to store the original list that are not in the set 'st'.
        while head!=None:   # while the current node is not None (i.e.. we have not reached the end of lineked list):
            if head.val not in st:  # If the current node's value is not int the set 'st'.
                li.append(head.val)  # Append the value to the list 'li'.
            head=head.next            # Move to the next node in the list.
        dummy =  ListNode(0)      # Created a dummy node as the starting point of the new linked list
        node = dummy        # Pointer 'node' is used to build the new linked list.
        n =len(li)          # Get the number of filtered elements
        for i in range(n):  # Traverse through the 'li' list to create the modified linked list.
            newNode = ListNode(li[i])    # Created a new node for each element in 'li'.
            node.next=newNode            # Link the current node to this new Node.
            node=node.next               # Move the pointer to the next node .
        return dummy.next    # Return the head of the new linked list (skipping the dummy node).


        
