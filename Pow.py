class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1
        neg = False
        if n < 0:
            neg = True
            n = -n
        y = 1
        while n>1:
            t = n % 2
            n = n // 2
            if t:
                y *= x
                
            x *= x
            
        #print(x,y)

        y *= x
        if neg:
            return 1.0/y
        return y

s = Solution()
print(s.myPow(3.4, -5) - 3.4**(-5))