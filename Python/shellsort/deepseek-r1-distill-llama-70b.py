
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


