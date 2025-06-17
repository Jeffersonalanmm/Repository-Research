import random
import time

def binary_search(arr, target):
    """
    This function performs a binary search on a sorted array to find the index of a target value.
    
    Parameters:
    arr (list): A sorted list of integers.
    target (int): The target value to be searched in the list.
    
    Returns:
    int: The index of the target value if found, -1 otherwise.
    """
    low = 0
    high = len(arr) - 1
    
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return -1

# Generate 1000 random inputs
random_inputs = [random.randint(1, 1000) for _ in range(1000)]
random_inputs.sort()

# Measure the execution time of the binary search algorithm
start_time = time.time()
for target in random_inputs:
    binary_search(random_inputs, target)
end_time = time.time()

# Calculate the execution time
execution_time = end_time - start_time

# Store the results
results = [binary_search(random_inputs, target) for target in random_inputs]

# Calculate the number of successful searches
successful_searches = sum(1 for result in results if result != -1)
