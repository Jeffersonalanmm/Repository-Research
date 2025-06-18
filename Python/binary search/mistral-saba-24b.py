import random

def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

# Generate 1000 random integers sorted in ascending order
random_inputs = sorted(random.randint(0, 10000) for _ in range(1000))

# Perform binary search on the sorted list
target = random.choice(random_inputs)
result = binary_search(random_inputs, target)