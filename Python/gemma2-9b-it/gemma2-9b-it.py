def bubblesort(arr):
    """
    Optimized implementation of the Bubblesort algorithm.

    Args:
        arr (list): The list of elements to be sorted.

    Returns:
        list: The sorted list of elements.
    """
    n = len(arr)

    for i in range(n):
        # Create a flag that will allow the function to terminate early if there's nothing left to sort
        swapped = False

        # Start looking at each item of the list one by one, comparing it with its adjacent value
        for j in range(0, n - i - 1):
            # If we find an element that is greater than its adjacent element, then swap them
            if arr[j] > arr[j + 1]:
                # Swap values
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                # Set the flag to True so we'll loop again after this iteration
                swapped = True

        # If no two elements were swapped in the inner loop, the list is sorted
        if not swapped:
            break

    return arr


# Example usage with 1000 inputs
import random
arr = [random.randint(0, 1000) for _ in range(1000)]
sorted_arr = bubblesort(arr)