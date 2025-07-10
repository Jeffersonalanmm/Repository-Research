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
import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = gnome_sort(arr)

if __name__ == "__main__":
    main()
