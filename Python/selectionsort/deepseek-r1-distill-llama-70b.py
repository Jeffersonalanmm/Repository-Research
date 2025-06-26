
def optimized_selection_sort(arr):
    arr = arr.copy()
    n = len(arr)
    left = 0
    right = n - 1
    
    while left < right:
        # Find min and max in the current subarray
        min_val = max_val = arr[left]
        min_idx = max_idx = left
        
        for i in range(left, right + 1):
            if arr[i] < min_val:
                min_val = arr[i]
                min_idx = i
            if arr[i] > max_val:
                max_val = arr[i]
                max_idx = i
        
        # Swap min with left element if needed
        if min_idx != left:
            arr[left], arr[min_idx] = arr[min_idx], arr[left]
            # If the swapped element was the max, update max_idx
            if min_idx == max_idx:
                max_idx = left
            max_val = arr[max_idx]
        
        # Swap max with right element if needed
        if max_idx != right:
            arr[right], arr[max_idx] = arr[max_idx], arr[right]
        
        left += 1
        right -= 1
    
    return arr

# Example usage
if __name__ == "__main__":
    import random
    random.seed(42)
    arr = [random.randint(0, 1000) for _ in range(1000)]
    sorted_arr = optimized_selection_sort(arr)
    # Verify the sort (no print statements)
    for i in range(1, len(sorted_arr)):
        if sorted_arr[i] < sorted_arr[i-1]:
            pass