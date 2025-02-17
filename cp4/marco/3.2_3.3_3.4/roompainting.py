def lower_bound(arr, target):
    """
    Finds the index of the first element in the sorted array `arr` that is not less than `target`.
    If all elements are less than `target`, returns len(arr).

    :param arr: A sorted list of elements.
    :param target: The value to find the lower bound for.
    :return: The index of the lower bound.
    """
    low, high = 0, len(arr)
    while low < high:
        mid = (low + high) // 2
        if arr[mid] < target:
            low = mid + 1
        else:
            high = mid
    return low

# # Example usage:
# arr = [1, 3, 5, 7, 9]
# target = 6
# index = lower_bound(arr, target)
# print(f"Lower bound for {target} is at index {index}")  # Output: Lower bound for 6 is at index 3

def read_input():
    # First line specifies n and m
    n, m = map(int, input().split())
    
    # Read the next n lines
    n_nums = [int(input()) for _ in range(n)]
    
    # Read the next m lines
    m_nums = [int(input()) for _ in range(m)]
    
    return n, m, n_nums, m_nums

# Example usage:
n, m, n_nums, m_nums = read_input()

tot = 0
for i in m_nums:
    tot += i 
comp = 0
for i in range(len(m_nums)):
    idx = lower_bound(n_nums, m_nums[i])
    comp += n_nums[idx] - m_nums[i]
    
    
print(comp)
# print(f"n: {n}, m: {m}")
# print(f"n_nums: {n_nums}")
# print(f"m_nums: {m_nums}")

