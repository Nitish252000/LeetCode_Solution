class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        ans = [0] * len(arr)
        arr1 = sorted(arr)  # sorted() returns a new sorted list without modifying arr

        mp= {}  #create a dictionary
        rank = 1
        for i in range(len(arr1)):
            if i>0 and arr1[i]>arr1[i-1]:
                rank+=1
            mp[arr1[i]]=rank
        for i in range(len(arr)):
            ans[i]=mp[arr[i]]
        return ans
