def gnome_sort(arr):
    last_swap_pos = -1
    i = 0
    n = len(arr)
    while i < n - 1:
        if arr[i] > arr[i + 1]:
            arr[i], arr[i + 1] = arr[i + 1], arr[i]
            last_swap_pos = i
            i = max(0, i - 1)
        else:
            if last_swap_pos != -1 and i > last_swap_pos:
                last_swap_pos = -1
            i += 1
    return arr

# Example usage with 1000 random inputs (example with 5 elements for demonstration)
import random

def main():
    arr = [random.randint(0, 1000) for _ in range(5)]  # Change 5 to 1000 for more elements
    print("Unsorted array:", arr)
    sorted_arr = gnome_sort(arr)
    print("Sorted array:", sorted_arr)

if __name__ == "__main__":
    main()
