class ProductOfNumbers:
    #------------will give TLE----------
    # def __init__(self):
    #     self.stream=[]  # Instance variable (not a class variable)

    # def add(self, num: int) -> None:
    #     self.stream.append(num)

    # def getProduct(self, k: int) -> int:
    #     pro=1
    #     n=len(self.stream)
    #     for i in range(n-1,n-k-1,-1):
    #         if self.stream[i]==0:return 0
    #         pro*=self.stream[i]
    #     return pro
    def __init__(self):
        self.prefix = [1]  # Store prefix products, initialized with 1

    def add(self, num: int) -> None:
        if num == 0:
            self.prefix = [1]  # Reset if a zero is encountered
        else:
            self.prefix.append(self.prefix[-1] * num)  # Store cumulative product
    
    def getProduct(self, k: int) -> int:
        if k >= len(self.prefix):  # If k exceeds available elements (due to reset)
            return 0
        return self.prefix[-1] // self.prefix[-k - 1]  # Get product in O(1) using division
# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
