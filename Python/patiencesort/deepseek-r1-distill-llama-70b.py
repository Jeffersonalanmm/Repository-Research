
import bisect
import heapq
import random

def patience_sort(iterable):
    piles = []
    tops = []
    for x in iterable:
        idx = bisect.bisect_right(tops, x)
        if idx == 0:
            piles.append([x])
            tops.append(x)
        else:
            piles[idx].append(x)
            tops[idx] = x
    heap = []
    for i, pile in enumerate(piles):
        if pile:
            heapq.heappush(heap, (pile[0], i, 0))
    result = []
    while heap:
        val, pile_idx, count = heapq.heappop(heap)
        result.append(val)
        if count + 1 < len(piles[pile_idx]):
            next_val = piles[pile_idx][count + 1]
            heapq.heappush(heap, (next_val, pile_idx, count + 1))
    return result

# Generate 1000 random inputs
random_list = [random.randint(0, 10000) for _ in range(1000)]
# Sort using patience_sort
sorted_list = patience_sort(random_list)
