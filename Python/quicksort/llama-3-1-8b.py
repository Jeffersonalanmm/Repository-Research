
def quick_sort(arr):
    """
    Optimized implementation of the quick sort algorithm.

    This function uses the 'Lomuto' partition scheme, which is a variation of the standard 'Hoare' partition scheme.
    It is slightly faster and more efficient in practice.

    :param arr: The input array to be sorted.
    :return: The sorted array.
    """
    _quick_sort_helper(arr, 0, len(arr) - 1)


def _quick_sort_helper(arr, low, high):
    """
    Recursive helper function for the quick sort algorithm.

    :param arr: The input array to be sorted.
    :param low: The low index of the current partition.
    :param high: The high index of the current partition.
    """
    if low < high:
        # Partition the array and get the pivot index
        pivot_index = _partition(arr, low, high)

        # Recursively sort the sub-arrays on either side of the pivot
        _quick_sort_helper(arr, low, pivot_index - 1)
        _quick_sort_helper(arr, pivot_index + 1, high)


def _partition(arr, low, high):
    """
    Partition the array around a pivot element.

    This function uses the 'Lomuto' partition scheme.

    :param arr: The input array to be partitioned.
    :param low: The low index of the current partition.
    :param high: The high index of the current partition.
    :return: The index of the pivot element.
    """
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


# Example usage:
import random

# Generate a random array of 1000 elements
arr = [random.randint(0, 1000) for _ in range(1000)]

# Sort the array using quick sort
quick_sort(arr)

# Verify that the array is sorted
assert all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))
