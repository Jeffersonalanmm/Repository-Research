import random

def shell_sort(arr):
    n = len(arr)
    gap = n//2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j-gap] > temp:
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
        gap //= 2

    return arr

# Generate 1000 random inputs
arr = [random.randint(1, 1000) for _ in range(1000)]

# Call the shell_sort function
sorted_arr = shell_sort(arr)