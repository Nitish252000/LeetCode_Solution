class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        newNode = ListNode(0)
        node = newNode
        curr=head.next
        while curr !=None:
            sum=0
            while curr.val!=0:
                sum=sum+curr.val
                curr=curr.next
            curr=curr.next
            temp=ListNode(sum)
            node.next=temp
            node=node.next
        result = newNode.next
        return result
