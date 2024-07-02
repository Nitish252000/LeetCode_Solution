class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        n1=len(nums1)
        n2=len(nums2)
        ans = []
        nums1.sort()
        nums2.sort()
        i=0 
        j=0
        while i<n1 and j<n2:
            if nums1[i]<nums2[j]:
                i+=1
            elif nums1[i]>nums2[j]:
                j+=1
            else:
                ans.append(nums1[i])
                i+=1
                j+=1
        return ans
        
