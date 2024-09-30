class CustomStack:
    
    def __init__(self, maxSize: int):
        self.stacklist = [0]*maxSize
        self.topIndex=-1
        self.maxSize=maxSize

    def push(self, x: int) -> None:
        if self.topIndex<self.maxSize-1:
            self.topIndex=self.topIndex+1
            self.stacklist[self.topIndex]=x

    def pop(self) -> int:
        if self.topIndex>=0:
            poppedVal= self.stacklist[self.topIndex]
            self.topIndex-=1
            return poppedVal
        return -1
    def increment(self, k: int, val: int) -> None:
        n = min(k,self.topIndex+1)
        for i in range(n):
            self.stacklist[i]+=val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
