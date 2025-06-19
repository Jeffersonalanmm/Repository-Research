import random

def gnome_sort(arr):
    index = 0
    n = len(arr)

    while index < n:
        if index == 0:
            index += 1
        if arr[index] >= arr[index - 1]:
            index += 1
        else:
            arr[index], arr[index - 1] = arr[index - 1], arr[index]
            index -= 1

# Generate 1000 random integers
random_inputs = [random.randint(0, 10000) for _ in range(1000)]

# Sort the array using gnome sort
gnome_sort(random_inputs)