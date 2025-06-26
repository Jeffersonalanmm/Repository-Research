
def shell_sort(arr):
    gaps = [701, 301, 132, 57, 23, 11, 6, 3, 2, 1]
    for gap in gaps:
        if gap > len(arr):
            continue
        for i in range(gap, len(arr)):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
    return arr

# Example usage:
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original array:", arr)
print("Sorted array:", shell_sort(arr))
