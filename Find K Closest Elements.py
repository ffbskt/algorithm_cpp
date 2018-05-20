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

def grad(arr, ri, k, x):
    dl, dr = False, False
    if len(arr) - 1 > ri:
        dr = (abs(arr[ri] - x) + abs(x - arr[ri - k]) > 
              abs(arr[ri + 1] - x) + abs(x - arr[ri + 1 - k]))
        #print((abs(arr[ri] - x) + abs(x - arr[ri - k]), 
        #      abs(arr[ri + 1] - x) + abs(x - arr[ri + 1 - k])))
    elif ri - k > 0:
        #print(ri, len(arr), k)
        dl = (abs(arr[ri] - x) + abs(x - arr[ri - k]) > 
              abs(arr[ri - 1] - x) + abs(x - arr[ri - 1 - k]))
    else:
        return False #the arr ended
    if dr:
        return 'r'
    elif dl:
        return 'l'
    return False

class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        L, R = 0, len(arr)
        
        while L <= R:
            rind = max((L + R) // 2, k)
            #rind = max(rind, k)
            move = grad(arr, rind, k, x)
            #print('1', move,rind)
            if move == 'r':
                L = rind + 1
            elif move == 'l':
                R = rind - 1
            else:
                return arr[rind-k+1:rind+1]

#print(grad([1,2,3,4,5,8], 4, 4, 5))
    

s = Solution()
print(s.findClosestElements([1,2,3,4,5,8], k=4, x=4))
#print(s.findClosestElements([1,2,3,4,5,7], k=4, x=6))
    
