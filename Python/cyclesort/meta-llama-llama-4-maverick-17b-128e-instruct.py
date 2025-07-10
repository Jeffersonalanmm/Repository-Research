import random

def cycle_sort(arr):
    writes = 0
    n = len(arr)
    for cycleStart in range(n - 1):
        item = arr[cycleStart]
        pos = cycleStart
        for i in range(cycleStart + 1, n):
            if arr[i] < item:
                pos += 1
        if pos == cycleStart:
            continue
        while item == arr[pos]:
            pos += 1
        arr[pos], item = item, arr[pos]
        writes += 1
        while pos != cycleStart:
            pos = cycleStart
            for i in range(cycleStart + 1, n):
                if arr[i] < item:
                    pos += 1
            while item == arr[pos]:
                pos += 1
            arr[pos], item = item, arr[pos]
            writes += 1
    return arr

def generate_random_list(size):
    return [random.randint(0, 10000) for _ in range(size)]

import sys
def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    cycle_sort(arr)


if __name__ == "__main__":
    main()
