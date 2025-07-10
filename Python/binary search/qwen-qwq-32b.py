import random

def binary_search(arr, target):
    if not arr:
        return -1
    if target < arr[0] or target > arr[-1]:
        return -1
    low = 0
    high = len(arr) -1
    while low <= high:
        mid = (low + high) //2
        mid_val = arr[mid]
        if mid_val < target:
            low = mid +1
        elif mid_val > target:
            high = mid -1
        else:
            return mid
    return -1

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    arr.sort()  # binary_search requires sorted array

    target = 15
    binary_search(arr, target)
if __name__ == "__main__":
    main()