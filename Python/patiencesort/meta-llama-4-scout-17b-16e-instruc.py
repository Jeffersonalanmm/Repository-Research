import random
import bisect

def patience_sort(arr):
    piles = []
    for x in arr:
        i = bisect.bisect_left(piles, x)
        if i != len(piles):
            piles[i] = x
        else:
            piles.append(x)
    return piles

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = patience_sort(arr)


if __name__ == "__main__":
    main()