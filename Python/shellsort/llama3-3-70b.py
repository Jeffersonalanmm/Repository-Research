import random
import time

def shell_sort(arr):
    """
    Optimized implementation of the shell sort algorithm.

    Args:
        arr (list): The list of elements to be sorted.

    Returns:
        list: The sorted list of elements.
    """
    # Initialize the gap size
    gap = len(arr) // 2

    # Loop until the gap size is greater than zero
    while gap > 0:
        # Loop through the array starting from the gap size
        for i in range(gap, len(arr)):
            # Store the current element
            temp = arr[i]

            # Initialize the index for comparison
            j = i

            # Compare and shift elements until the correct position is found
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

            # Place the current element at the correct position
            arr[j] = temp

        # Reduce the gap size by half for the next iteration
        gap //= 2

    return arr


# Generate 1000 random inputs
random_inputs = [random.randint(1, 1000) for _ in range(1000)]

# Measure the execution time
start_time = time.time()
sorted_arr = shell_sort(random_inputs)
end_time = time.time()

# Calculate the execution time
execution_time = end_time - start_time

# Store the results
results = {
    "sorted_array": sorted_arr,
    "execution_time": execution_time
}