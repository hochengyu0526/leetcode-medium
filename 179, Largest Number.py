from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        if all(x == 0 for x in nums):
            return "0"
        
        # Convert numbers to strings for comparison
        nums = [str(x) for x in nums]
        
        # Use a more efficient sort than bubble sort
        from functools import cmp_to_key

        def compare_nums(a, b):
            if a + b > b + a:
                return -1 # a comes first
            elif a + b < b + a:
                return 1  # b comes first
            else:
                return 0
        
        nums.sort(key=cmp_to_key(compare_nums))
        
        return "".join(nums)

# Example usage for testing
if __name__ == "__main__":
    solution = Solution()
    
    nums1 = [10, 2]
    print(f"Input: {nums1}, Largest Number: {solution.largestNumber(nums1)}") # Expected: "210"

    nums2 = [3, 30, 34, 5, 9]
    print(f"Input: {nums2}, Largest Number: {solution.largestNumber(nums2)}") # Expected: "9534330"

    nums3 = [0, 0]
    print(f"Input: {nums3}, Largest Number: {solution.largestNumber(nums3)}") # Expected: "0"