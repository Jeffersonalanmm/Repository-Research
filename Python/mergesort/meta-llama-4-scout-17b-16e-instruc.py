
import random

def merge_sort(arr):
    """
    Optimized implementation of the merge sort algorithm.

    Args:
        arr (list): The list to be sorted.

    Returns:
        list: The sorted list.
    """
    # Base case: If the array has 1 or fewer elements, it's already sorted
    if len(arr) <= 1:
        return arr

    # Find the middle point and divide the array into two halves
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    # Recursively sort the two halves
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    # Merge the two sorted halves
    return merge(left_half, right_half)


def merge(left, right):
    """
    Merge two sorted lists into one.

    Args:
        left (list): The first sorted list.
        right (list): The second sorted list.

    Returns:
        list: The merged sorted list.
    """
    merged = []
    left_index = 0
    right_index = 0

    # Merge smaller elements first
    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            merged.append(left[left_index])
            left_index += 1
        else:
            merged.append(right[right_index])
            right_index += 1

    # If there are remaining elements in either half, append them to the merged list
    merged.extend(left[left_index:])
    merged.extend(right[right_index:])

    return merged


# Generate 1000 random inputs and test the merge sort implementation
random_inputs = [random.randint(0, 1000) for _ in range(1000)]
sorted_inputs = merge_sort(random_inputs)
assert all(sorted_inputs[i] <= sorted_inputs[i + 1] for i in range(len(sorted_inputs) - 1))