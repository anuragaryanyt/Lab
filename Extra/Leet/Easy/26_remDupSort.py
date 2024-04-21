#counting no of unique elements in the list after removing the duplicate elements

from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=0
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i+=1
                nums[i]=nums[j]
        return i+1

s=Solution()
nums=[1,1,2]
print(s.removeDuplicates(nums))

nums2=[0,0,1,1,1,2,2,3,3,4]
print(s.removeDuplicates(nums2))
