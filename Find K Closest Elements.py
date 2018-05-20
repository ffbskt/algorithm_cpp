def BinSearchNearest(arr, x):
    fin = len(arr) - 1
    start = 0
    while fin >= start:
        med = (fin + start) // 2
        if x == arr[med]:
            return med
        elif x > arr[med]:
            start = med + 1
        else:
            fin = med - 1
    if arr[start] > x:
        return start - 1
    return start


class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        ind = BinSearchNearest(arr, x)
        if k <= ind:
            return arr[ind - k:ind]
        else:
            return arr[0:k]
    


print (BinSearchNearest([1,2,3,4,5,8], 6))
print (BinSearchNearest([1,2,3,4,5,8], 5))
print (BinSearchNearest([1,2,3,4,5,8], 8))
s = Solution()
print(s.findClosestElements([1,2,3,4,5,8], k=4, x=5))
print(s.findClosestElements([1,2,3,4,5,8], k=4, x=6))
    
