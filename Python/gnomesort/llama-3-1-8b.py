
def gnome_sort(arr):
    """
    Gnome sort algorithm implementation.

    Args:
    arr (list): The list of elements to be sorted.

    Returns:
    list: The sorted list of elements.
    """
    if len(arr) <= 1:
        return arr

    pos = 0
    while pos < len(arr):
        if pos == 0 or arr[pos] >= arr[pos - 1]:
            pos += 1
        else:
            arr[pos], arr[pos - 1] = arr[pos - 1], arr[pos]
            if pos > 1:
                pos -= 1
    return arr

# Test the implementation with 1000 random inputs
import random

# Generate 1000 random lists of 100 elements each
random_lists = [[random.randint(0, 1000) for _ in range(100)] for _ in range(1000)]

# Measure the execution time
import time

start_time = time.time()
sorted_lists = [gnome_sort(lst) for lst in random_lists]
end_time = time.time()

# Check if the sorted lists are correct
for i, lst in enumerate(sorted_lists):
    assert all(lst[j] <= lst[j + 1] for j in range(len(lst) - 1)), f"List {i} is not sorted correctly"

# Measure the execution time
print(f"Execution time: {end_time - start_time} seconds")
