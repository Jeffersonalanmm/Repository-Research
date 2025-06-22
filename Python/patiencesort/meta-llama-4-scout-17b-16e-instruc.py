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

# Test with 1000 random inputs
arr = [random.randint(1, 1000) for _ in range(1000)]
patience_sort(arr)
