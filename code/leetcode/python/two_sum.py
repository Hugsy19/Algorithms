# leetcode 1

from typing import List


def twoSum_1(nums: List[int], target: int) -> List[int]:
    nums_len = len(nums)
    for i in range(nums_len):
        for j in range(i + 1, nums_len):
            if target == nums[i] + nums[j]:
                return i, j
    return []


def twoSum_2(nums: List[int], target: int) -> List[int]:
    nums_hash_dict = {}
    for index, first_num in enumerate(nums):
        second_num = target - first_num
        if second_num in nums_hash_dict:
            return [index, nums_hash_dict[second_num]]
        nums_hash_dict[first_num] = index
    return []


if __name__ == '__main__':
    while True:
        nums_str = input()
        target_str = input()
        nums = [int(x) for x in nums_str.split()]
        target = int(target_str)

        ret = twoSum_1(nums, target)
        if ret:
            print(f"[{ret[0]}, {ret[1]}]")

        ret = twoSum_2(nums, target)
        if ret:
            print(f"[{ret[0]}, {ret[1]}]")
