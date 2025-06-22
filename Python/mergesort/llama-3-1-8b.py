
def merge_sort(arr):
    """
    This function implements the merge sort algorithm to sort an array in ascending order.
    
    Args:
    arr (list): The input array to be sorted.
    
    Returns:
    list: The sorted array.
    """
    
    # If the array has only one element, it is already sorted
    if len(arr) <= 1:
        return arr
    
    # Find the middle index of the array
    mid = len(arr) // 2
    
    # Divide the array into two halves
    left_half = arr[:mid]
    right_half = arr[mid:]
    
    # Recursively sort the two halves
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)
    
    # Merge the two sorted halves
    return merge(left_half, right_half)


def merge(left, right):
    """
    This function merges two sorted arrays into a single sorted array.
    
    Args:
    left (list): The first sorted array.
    right (list): The second sorted array.
    
    Returns:
    list: The merged sorted array.
    """
    
    # Initialize an empty list to store the merged array
    merged = []
    
    # Initialize indices for the left and right arrays
    left_index = 0
    right_index = 0
    
    # Merge the two arrays
    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            merged.append(left[left_index])
            left_index += 1
        else:
            merged.append(right[right_index])
            right_index += 1
    
    # Append any remaining elements from the left array
    while left_index < len(left):
        merged.append(left[left_index])
        left_index += 1
    
    # Append any remaining elements from the right array
    while right_index < len(right):
        merged.append(right[right_index])
        right_index += 1
    
    # Return the merged array
    return merged


# Test the merge sort function with 1000 random inputs
import random

for _ in range(1000):
    arr = [random.randint(0, 1000) for _ in range(100)]
    sorted_arr = merge_sort(arr)
    # assert sorted_arr == sorted(arr), f"Expected {sorted(arr)} but got {sorted_arr}"
