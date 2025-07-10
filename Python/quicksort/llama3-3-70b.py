import random
import time

def quick_sort(arr):
    """
    This function implements the quick sort algorithm.
    
    :param arr: The list of elements to be sorted.
    :return: The sorted list of elements.
    """
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def test_quick_sort():
    """
    This function tests the quick sort algorithm with 1000 random inputs.
    """
    for _ in range(1000):
        arr = [random.randint(1, 1000) for _ in range(100)]
        start_time = time.time()
        sorted_arr = quick_sort(arr)
        end_time = time.time()
        assert sorted_arr == sorted(arr), "Quick sort failed"

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = quick_sort(arr)


if __name__ == "__main__":
    main()
