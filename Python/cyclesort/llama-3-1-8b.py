
def cycle_sort(arr):
    """
    Optimized implementation of the cycle sort algorithm.

    Args:
    arr (list): The input list to be sorted.

    Returns:
    list: The sorted list.
    """
    writes = 0
    for cycle_start in range(len(arr) - 1):
        item = arr[cycle_start]
        pos = cycle_start

        # Find the item's correct position
        for i in range(cycle_start + 1, len(arr)):
            if arr[i] < item:
                pos += 1

        # If the item is already there, this is not a cycle
        if pos == cycle_start:
            continue

        # Otherwise, put the item there or right after any duplicates
        while item == arr[pos]:
            pos += 1
        arr[pos], item = item, arr[pos]
        writes += 1

        # Rotate the rest of the cycle to the beginning
        while pos != cycle_start:
            pos = cycle_start
            while arr[pos] == item:
                pos += 1
            arr[pos], item = item, arr[pos]
            writes += 1

    return arr
arr = [4, 2, 1, 3]
sorted_arr = cycle_sort(arr)
