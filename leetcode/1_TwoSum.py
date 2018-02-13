def twoSum(nums, target):# cost 600ms
    """
    :type nums: List[int]
    :type target: int
    :rtype : List[int]
    """
    result = []
    for i in range(0, len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] + nums[j] == target:
                result.append(i)
                result.append(j)
                return result


print twoSum([1, 2, 3, 4], 7)
