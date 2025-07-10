
import random

def patience_sort(arr):
    piles = []
    for card in arr:
        if not piles or piles[-1][-1] >= card:
            piles.append([card])
        else:
            for pile in piles:
                if pile and pile[-1] <= card:
                    pile.append(card)
                    break
            else:
                piles.append([card])
    return [card for pile in piles for card in pile]

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
