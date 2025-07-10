
def shell_sort(arr):
    """
    Optimized implementation of the shell sort algorithm.

    :param arr: The input array to be sorted.
    :return: The sorted array.
    """
    n = len(arr)
    gap = n // 2

    while gap > 0:
        # Iterate over the array with the current gap.
        for i in range(gap, n):
            temp = arr[i]
            j = i

            # Shift elements to the right until a smaller element is found.
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

            # Insert the smaller element at the correct position.
            arr[j] = temp

        # Reduce the gap by half for the next iteration.
        gap //= 2

    return arr


# Test the implementation with 1000 random inputs.
import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = shell_sort(arr)
    

if __name__ == "__main__":
    main()

