def binary_search(arr, target):
    """
    This function performs a binary search on a sorted array to find the index of the target value.
    
    Args:
        arr (list): A sorted list of elements.
        target (int/float): The value to be searched in the list.
    
    Returns:
        int: The index of the target value if found, otherwise -1.
    """
    low = 0
    high = len(arr) - 1
    
    while low <= high:
        mid = (low + high) // 2  # Using integer division to avoid floating point
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1  # Search in the right half
        else:
            high = mid - 1  # Search in the left half
    
    return -1  # Target not found in the array

# Example usage
if __name__ == "__main__":
    import random
    random.seed(42)  # For reproducibility
    
    # Generate 1000 random sorted lists and test the binary_search function
    for _ in range(1000):
        arr = sorted([random.randint(1, 1000) for _ in range(random.randint(10, 100))])
        target = random.choice(arr)
        index = binary_search(arr, target)
        assert index != -1, "Target not found in the sorted array"
        
        # Test a value not in the array
        target_not_present = random.randint(1001, 2000)
        index_not_present = binary_search(arr, target_not_present)
        assert index_not_present == -1, "Target not present but found in the array"
