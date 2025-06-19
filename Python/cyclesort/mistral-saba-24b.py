
import random

def cycle_sort(arr):
    n = len(arr)
    writes = 0

    # Loop through the array to find cycles to rotate.
    for cycle_start in range(0, n - 1):
        item = arr[cycle_start]

        # Find where to place the item.
        pos = cycle_start
        for i in range(cycle_start + 1, n):
            if arr[i] < item:
                pos += 1

        # If the item is already in the correct position, continue.
        if pos == cycle_start:
            continue

        # Otherwise, put the item in the right position.
        while item == arr[pos]:
            pos += 1
        arr[pos], item = item, arr[pos]
        writes += 1

        # Rotate the rest of the cycle.
        while pos != cycle_start:
            pos = cycle_start
            for i in range(cycle_start + 1, n):
                if arr[i] < item:
                    pos += 1

            while item == arr[pos]:
                pos += 1
            arr[pos], item = item, arr[pos]
            writes += 1

    return arr, writes

# Generate 1000 random integers
random_inputs = [random.randint(0, 10000) for _ in range(1000)]

# Perform cycle sort on the random inputs
sorted_array, write_count = cycle_sort(random_inputs)
