class Solution(object):
    def gcd(self,a,b):
        if b==0:
            return a
        return self.gcd(b,a%b)
    def replaceNonCoprimes(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        st=[]
        for num in nums:
            st.append(num)
            while len(st)>1:
                a,b=st[-2],st[-1]
                g = self.gcd(a, b)
                if g>1:
                    st.pop()
                    st.pop()
                    lcm=a*b//g
                    st.append(lcm)
                else:
                    break
        return st
