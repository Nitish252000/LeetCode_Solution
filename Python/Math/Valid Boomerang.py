class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        # x1=points[0][0]  
        # y1=points[0][1]
        # x2=points[1][0] 
        # y2=points[1][1]
        # x3=points[2][0] 
        # y3=points[2][1]
        x1,y1=points[0]
        x2,y2=points[1]
        x3,y3=points[2]
        # check all points are distinct?
        if (x1==x2 and y1==y2) or (x2==x3 and y2==y3) or (x1==x3 and y1==y3):
            return False
        
        # Check for collinearity using the cross product
        return (x2 - x1) * (y3 - y1) != (y2 - y1) * (x3 - x1)
