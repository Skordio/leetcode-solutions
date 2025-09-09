from typing import List

# Solution I came up with off the top of my head
class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1_count_dict = {}
        nums_count_dict = {}

        for num in nums1:
            if num in nums1_count_dict.keys():
                nums1_count_dict[num] += 1
            else:
                nums1_count_dict[num] = 1
        
        for num in nums2:
            if num in nums_count_dict.keys():
                nums_count_dict[num] += 1
            else:
                nums_count_dict[num] = 1

        answer1 = 0
        answer2 = 0

        for num in nums_count_dict.keys():
            if num in nums1_count_dict.keys():
                answer1 += nums1_count_dict[num]

        for num in nums1_count_dict.keys():
            if num in nums_count_dict.keys():
                answer2 += nums_count_dict[num]

        return [answer1, answer2]