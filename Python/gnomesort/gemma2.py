
import random

def gnome_sort(arr):
  index = 1
  while index < len(arr):
    if arr[index] >= arr[index - 1]:
      index += 1
    else:
      arr[index], arr[index - 1] = arr[index - 1], arr[index]
      index -= 1
  return arr

# Generate 1000 random integers
data = [random.randint(1, 1000) for _ in range(1000)]

# Apply gnome sort
gnome_sort(data) 
