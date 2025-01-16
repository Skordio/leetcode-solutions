class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1_counter = m-1
        nums2_counter = n-1

        insert_place = len(nums1)-1

        if m == 0:
            nums1[0] = nums2[0]
            return

        while nums1_counter >= 0 and nums2_counter >= 0:
            if nums1[nums1_counter] > nums2[nums2_counter]:
                nums1[insert_place] = nums1[nums1_counter]
                nums1_counter -= 1
            else:
                nums1[insert_place] = nums2[nums2_counter]
                nums2_counter -= 1
            insert_place -= 1


def main():
    nums1 = [1, 2, 3, 0, 0, 0]
    m = 3
    nums2 = [2, 5, 6]
    n = 3

    s = Solution()
    s.merge(nums1, m, nums2, n)
    print(nums1)

if __name__ == '__main__':
    main()