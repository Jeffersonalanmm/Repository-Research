
import random

def patience_sort(arr):
  n = len(arr)
  sorted_arr = []
  piles = []

  for i in range(n):
    current_pile = 0
    while current_pile < len(piles) and arr[i] > piles[current_pile][-1]:
      current_pile += 1
    if current_pile == len(piles):
      piles.append([arr[i]])
    else:
      piles[current_pile].append(arr[i])

  for pile in piles:
    sorted_arr.extend(pile)

  return sorted_arr

# Generate 1000 random integers
random_array = [random.randint(1, 1000) for _ in range(1000)]

# Apply patience sort
sorted_array = patience_sort(random_array) 
