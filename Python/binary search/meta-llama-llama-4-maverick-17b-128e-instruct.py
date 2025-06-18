
import random

def binary_search(arr, target):
    """
    Searches for the target element in the given sorted array using Binary Search.

    Args:
        arr (list): A sorted list of elements.
        target: The element to be searched.

    Returns:
        int: The index of the target element if found, -1 otherwise.
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

# Generate a sorted list of 1000 random integers
random_list = sorted([random.randint(1, 10000) for _ in range(1000)])
target_element = random.choice(random_list)

# Perform binary search
result = binary_search(random_list, target_element)
assert result != -1
