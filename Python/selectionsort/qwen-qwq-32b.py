
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_val = arr[i]
        min_idx = i
        for j in range(i+1, n):
            current = arr[j]
            if current < min_val:
                min_val = current
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = selection_sort(arr)
    

if __name__ == "__main__":
    main()

