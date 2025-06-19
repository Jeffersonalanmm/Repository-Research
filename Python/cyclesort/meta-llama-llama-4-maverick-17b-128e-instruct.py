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

if __name__ == "__main__":
    random_list = generate_random_list(1000)
    sorted_list = cycle_sort(random_list)