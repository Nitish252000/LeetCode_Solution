class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        ans=0
        for i in boxTypes:
            mini = min(truckSize,i[0])
            ans+=mini*i[1]
            truckSize-=mini
            if truckSize == 0:
                break
        return ans




# boxTypes.sort(key=lambda x: x[1], reverse=True)

# Explanation
# This line sorts the boxTypes list in-place in descending order based on the number of units per box. Here's how it works step-by-step:

# boxTypes List:

# boxTypes is a list of lists, where each sublist represents a type of box. For example:

# boxTypes = [[1, 3], [2, 2], [3, 1]]
# Each sublist [number_of_boxes, units_per_box] contains two integers.
# sort Method:

# The sort method sorts the list in-place, meaning it modifies the original list and doesn't return a new list.
# key Parameter:

# The key parameter specifies a function that is called on each element of the list before making comparisons.
# Here, key=lambda x: x[1] is a lambda function (an anonymous function) that takes one parameter x (which is a sublist in boxTypes) and returns the second element of x (x[1]).
# lambda x: x[1]:

# The lambda function extracts the second element from each sublist.
# For example, if x = [1, 3], then lambda x: x[1] returns 3.
# reverse=True:

# This argument tells the sort method to sort the list in descending order.
# If reverse were False or omitted, the list would be sorted in ascending order.
