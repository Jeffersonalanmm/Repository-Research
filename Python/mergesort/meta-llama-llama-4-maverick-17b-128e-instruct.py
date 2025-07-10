
import random

def merge_sort(arr):
    """
    Sorts an array using the merge sort algorithm.

    Args:
        arr (list): The input array to be sorted.

    Returns:
        list: The sorted array.
    """
    # Base case: If the array has 1 or 0 elements, it is already sorted.
    if len(arr) <= 1:
        return arr

    # Divide the array into two halves.
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    # Recursively sort the two halves.
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    # Merge the two sorted halves.
    return merge(left_half, right_half)


def merge(left, right):
    """
    Merges two sorted arrays into a single sorted array.

    Args:
        left (list): The first sorted array.
        right (list): The second sorted array.

    Returns:
        list: The merged sorted array.
    """
    merged = []
    left_index = 0
    right_index = 0

    # Merge the two arrays by comparing elements and adding the smaller one.
    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            merged.append(left[left_index])
            left_index += 1
        else:
            merged.append(right[right_index])
            right_index += 1

    # Append any remaining elements from the left and right arrays.
    merged.extend(left[left_index:])
    merged.extend(right[right_index:])

    return merged


def generate_random_array(size):
    """
    Generates an array of random integers.

    Args:
        size (int): The size of the array.

    Returns:
        list: The generated array.
    """
    return [random.randint(0, 1000) for _ in range(size)]


import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = merge_sort(arr)


if __name__ == "__main__":
    main()
