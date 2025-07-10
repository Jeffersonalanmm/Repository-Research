
import random

def shell_sort(arr):
    gaps = [1,4,13,40,121, 364, 1093]
    n = len(arr)
    gaps = [g for g in gaps if g < n]
    gaps.reverse()
    for gap in gaps:
        for i in range(gap, n):
            val = arr[i]
            j = i
            while j >= gap and arr[j - gap] > val:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = val


import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = shell_sort(arr)


if __name__ == "__main__":
    main()

