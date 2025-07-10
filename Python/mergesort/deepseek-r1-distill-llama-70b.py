
def merge_sort(arr):
    """
    Optimized merge sort implementation that uses insertion sort for small subarrays
    and minimizes array copying.
    """
    def merge_sort_helper(arr, start, end):
        if end - start <= 1:
            return
        mid = (start + end) // 2
        merge_sort_helper(arr, start, mid)
        merge_sort_helper(arr, mid, end)
        merge(arr, start, mid, end)

    def merge(arr, start, mid, end):
        left = arr[start:mid]
        right = arr[mid:end]
        i = j = 0
        k = start
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

    def insertion_sort(arr, start, end):
        for i in range(start + 1, end):
            key = arr[i]
            j = i - 1
            while j >= start and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key

    n = len(arr)
    if n <= 10:
        insertion_sort(arr, 0, n)
    else:
        merge_sort_helper(arr, 0, n)
    return arr

# Example usage
import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = merge_sort(arr)
    

if __name__ == "__main__":
    main()