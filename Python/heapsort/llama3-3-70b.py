
import random
import time

def heapify(arr, n, i):
    """
    Heapify the array.
    
    :param arr: The input array.
    :param n: The size of the array.
    :param i: The index to start heapifying from.
    :return: None
    """
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[i] < arr[left]:
        largest = left

    if right < n and arr[largest] < arr[right]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heap_sort(arr):
    """
    Sort the array using heap sort.
    
    :param arr: The input array.
    :return: The sorted array.
    """
    n = len(arr)

    # Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements one by one
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

    return arr


# Generate 1000 random inputs
inputs = [random.sample(range(1, 1000), random.randint(1, 100)) for _ in range(1000)]

# Measure the execution time
start_time = time.time()
for arr in inputs:
    heap_sort(arr)
end_time = time.time()

# Calculate the average execution time
average_time = (end_time - start_time) / len(inputs)
