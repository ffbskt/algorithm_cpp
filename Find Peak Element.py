def grad(arr, p):
    
    if (p > 0 and arr[p - 1] > arr[p]) and (p == len(arr) - 1 or arr[p] > arr[p + 1]):
        return 'l'
    if (p == 0 or arr[p - 1] < arr[p]) and (p < len(arr) - 1 and arr[p] < arr[p + 1]):
        return 'r'
    return 0

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums) - 1
        while r > l:
            mid = (r + l) // 2
            #print(mid,grad(nums, mid))
            if nums[mid] > nums[mid+1]:
                r = mid
            else:
                l = mid + 1
            
        return l
    
s = Solution()
print(s.findPeakElement([2,1,2]))
          