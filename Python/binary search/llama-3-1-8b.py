
def binary_search(arr, target):
    """
    Optimized implementation of the Binary Search Algorithm.

    Args:
    arr (list): A sorted list of elements.
    target: The element to be searched in the list.

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

# Test the function with 1000 random inputs
import random

arr = sorted([random.randint(0, 1000) for _ in range(1000)])
target = random.choice(arr)

result = binary_search(arr, target)
