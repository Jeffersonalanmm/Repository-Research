import random

def shell_sort(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# Generate 1000 random integers
random_inputs = [random.randint(0, 10000) for _ in range(1000)]

# Sort the list using shell sort
shell_sort(random_inputs)