
import random

def beadsort(arr):
    n = len(arr)
    # Create a 2D list to represent the beads
    beads = [['.' for _ in range(n)] for _ in range(max(arr))]

    # Place beads in the 2D list
    for i in range(n):
        for j in range(arr[i]):
            beads[j][i] = 'O'

    # Sort the beads
    for i in range(n):
        count = 0
        for j in range(n):
            if beads[j][i] == 'O':
                count += 1
        for j in range(n):
            if j < count:
                beads[j][i] = 'O'
            else:
                beads[j][i] = '.'

    # Extract the sorted array
    sorted_arr = []
    for i in range(n):
        count = 0
        for j in range(n):
            if beads[j][i] == 'O':
                count += 1
        sorted_arr.append(count)

    return sorted_arr

# Generate 1000 random inputs
random_inputs = [random.randint(0, 100) for _ in range(1000)]

# Sort the random inputs using beadsort
sorted_inputs = beadsort(random_inputs)

