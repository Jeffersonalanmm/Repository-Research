
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

# Generate 1000 random integers
random_inputs = [random.randint(0, 10000) for _ in range(1000)]

# Perform patience sort on the random inputs
sorted_array = patience_sort(random_inputs)
