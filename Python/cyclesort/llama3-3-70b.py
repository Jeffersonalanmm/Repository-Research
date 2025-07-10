
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


import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    cycle_sort(arr)
if __name__ == "__main__":
    main()

