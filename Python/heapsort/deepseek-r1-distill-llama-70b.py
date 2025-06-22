
import random

def heapify(arr, n, i):
    """
    Transforms a subtree rooted at index i into a max heap.
    
    Args:
        arr (list): The array to heapify.
        n (int): The size of the heap.
        i (int): The root index of the subtree to heapify.
    """
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    
    if left < n and arr[left] > arr[largest]:
        largest = left
    
    if right < n and arr[right] > arr[largest]:
        largest = right
    
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def build_heap(arr):
    """
    Constructs a max heap from the given array.
    
    Args:
        arr (list): The array to build the heap from.
    """
    n = len(arr)
    
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

def heap_sort(arr):
    """
    Sorts the array using heap sort algorithm.
    
    Args:
        arr (list): The array to sort.
    
    Returns:
        list: The sorted array.
    """
    if not arr:
        return []
    
    sorted_arr = arr.copy()
    n = len(sorted_arr)
    
    build_heap(sorted_arr)
    
    for i in range(n - 1, 0, -1):
        sorted_arr[0], sorted_arr[i] = sorted_arr[i], sorted_arr[0]
        heapify(sorted_arr, i, 0)
    
    return sorted_arr

def main():
    # Test with random input
    random_input = [random.randint(0, 1000) for _ in range(1000)]
    sorted_output = heap_sort(random_input)
    
    # Test with ascending order
    ascending = list(range(10))
    sorted_ascending = heap_sort(ascending)
    
    # Test with descending order
    descending = list(range(9, -1, -1))
    sorted_descending = heap_sort(descending)
    
    # Test with duplicate values
    duplicates = [5, 2, 8, 2, 5, 1]
    sorted_duplicates = heap_sort(duplicates)

if __name__ == "__main__":
    main()
