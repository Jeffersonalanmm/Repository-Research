
import random
import time

def cycle_sort(arr):
    """
    Cycle sort algorithm implementation.

    :param arr: The input list to be sorted.
    :return: The sorted list.
    """
    writes = 0
    n = len(arr)

    for cycle_start in range(n - 1):
        item = arr[cycle_start]
        pos = cycle_start

        for i in range(cycle_start + 1, n):
            if arr[i] < item:
                pos += 1

        if pos == cycle_start:
            continue

        while item == arr[pos]:
            pos += 1
        arr[pos], item = item, arr[pos]
        writes += 1

        while pos != cycle_start:
            pos = cycle_start
            for i in range(cycle_start + 1, n):
                if arr[i] < item:
                    pos += 1

            while item == arr[pos]:
                pos += 1
            arr[pos], item = item, arr[pos]
            writes += 1

    return arr


# Generate 1000 random inputs
random_inputs = [random.sample(range(1, 1000), 10) for _ in range(1000)]

# Run cycle sort on each input
for inp in random_inputs:
    cycle_sort(inp)

# Measure execution time
start_time = time.time()
for inp in random_inputs:
    cycle_sort(inp)
end_time = time.time()

# Calculate average execution time
avg_time = (end_time - start_time) / len(random_inputs)
