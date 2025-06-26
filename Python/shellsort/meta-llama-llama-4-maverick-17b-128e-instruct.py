import random

def shell_sort(arr):
    """
    Sorts an array using the shell sort algorithm.

    Args:
        arr (list): The list to be sorted.

    Returns:
        list: The sorted list.
    """
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

    return arr

# Generate 1000 random numbers and sort them
random_numbers = [random.randint(0, 10000) for _ in range(1000)]
sorted_numbers = shell_sort(random_numbers)