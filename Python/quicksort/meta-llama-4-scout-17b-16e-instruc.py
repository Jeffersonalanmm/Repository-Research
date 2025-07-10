import random

def quick_sort(arr):
    _quick_sort(arr, 0, len(arr) - 1)
    return arr

def _quick_sort(arr, low, high):
    if low < high:
        pivot_index = _partition(arr, low, high)
        _quick_sort(arr, low, pivot_index - 1)
        _quick_sort(arr, pivot_index + 1, high)

def _partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

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
