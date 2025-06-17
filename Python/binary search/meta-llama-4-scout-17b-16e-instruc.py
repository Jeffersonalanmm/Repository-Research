import random

def binary_search(arr, target):
    """
    Optimized implementation of Binary Search Algorithm.

    Args:
    arr (list): A sorted list of integers.
    target (int): The target integer to be searched.

    Returns:
    int: The index of the target integer if found, -1 otherwise.
    """
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1

# Generate 1000 random inputs
arr = sorted([random.randint(1, 1000) for _ in range(1000)])
target = random.choice(arr)

result = binary_search(arr, target)
assert result != -1

# Edge cases
result = binary_search(arr, 0)
assert result == -1

result = binary_search([], 5)
assert result == -1

result = binary_search([5], 5)
assert result == 0