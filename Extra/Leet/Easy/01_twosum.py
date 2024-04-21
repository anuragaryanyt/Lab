from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map={}
        for i, num in enumerate(nums):
            complement=target-num
            if complement in num_map:
                return [num_map[complement][0], i]
            if num not in num_map:
                num_map[num] = []
            num_map[num].append(i)

        return []

s = Solution()

nums1 = [2, 7, 11, 15]
target1 = 9
print(s.twoSum(nums1, target1))

nums2 = [3, 2, 4]
target2 = 6
print(s.twoSum(nums2, target2))  