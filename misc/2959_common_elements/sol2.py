from typing import List

# Solution from solutions page on leetcode
class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:

        # Step 1: Build sets for fast presence checking
        set1 = set(nums1)
        set2 = set(nums2)

        answer1 = 0
        answer2 = 0

        # Step 2: Count how many elements in nums1 exist in nums2
        for num in nums1:
            if num in set2:
                answer1 += 1

        # Step 3: Count how many elements in nums2 exist in nums1
        for num in nums2:
            if num in set1:
                answer2 += 1

        # Step 4: Return results as a list
        return [answer1, answer2]