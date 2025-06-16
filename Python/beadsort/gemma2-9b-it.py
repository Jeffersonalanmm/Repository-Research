
import random

def beadsort(arr):
  max_val = max(arr)
  num_beads = max_val + 1
  beads = [0] * num_beads

  for num in arr:
    beads[num] += 1

  i = 0
  for j in range(num_beads):
    while beads[j] > 0:
      arr[i] = j
      beads[j] -= 1
      i += 1

  return arr

# Generate 1000 random inputs
random_inputs = [random.randint(0, 1000) for _ in range(1000)]

# Apply beadsort to the random inputs
sorted_inputs = beadsort(random_inputs.copy()) 
