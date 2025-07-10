def insertion_sort(arr, left, right):
    for i in range(left + 1, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge_sort(arr):
    if len(arr) < 2:
        return
    temp = [0] * len(arr)
    merge_sort_helper(arr, temp, 0, len(arr) - 1)


def merge_sort_helper(arr, temp, left, right):
    if right - left + 1 < 15:
        insertion_sort(arr, left, right)
        return
    if left < right:
        mid = (left + right) // 2
        merge_sort_helper(arr, temp, left, mid)
        merge_sort_helper(arr, temp, mid + 1, right)
        merge(arr, temp, left, mid, right)

def merge(arr, temp, left, mid, right):
    # Check if already sorted
    if arr[mid] <= arr[mid + 1]:
        return
    # Copy to temp array
    for i in range(left, right + 1):
        temp[i] = arr[i]
    a = left
    b = mid + 1
    curr = left
    while a <= mid and b <= right:
        if temp[a] <= temp[b]:
            arr[curr] = temp[a]
            a += 1
        else:
            arr[curr] = temp[b]
            b += 1
        curr += 1
    # Copy remaining elements from left
    while a <= mid:
        arr[curr] = temp[a]
        a += 1
        curr += 1
    
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