# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next==None:
            return head
        temp =head
        while temp.next != None:
            out = math.gcd(temp.val,temp.next.val)       ## node = ListNode() ## node.val= math.gcd(temp.val,temp.next.val)
            node = ListNode(out)
            curr = temp.next
            temp.next=node
            node.next=curr
            temp=temp.next.next
        return head


        
