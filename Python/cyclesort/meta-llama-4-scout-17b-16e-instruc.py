import random

def cycle_sort(array):
    writes = 0
    n = len(array)
    for cycleStart in range(n - 1):
        item = array[cycleStart]
        pos = cycleStart
        for i in range(cycleStart + 1, n):
            if array[i] < item:
                pos += 1
        if pos == cycleStart:
            continue
        while item == array[pos]:
            pos += 1
        array[pos], item = item, array[pos]
        writes += 1
        while pos != cycleStart:
            pos = cycleStart
            for i in range(cycleStart + 1, n):
                if array[i] < item:
                    pos += 1
            while item == array[pos]:
                pos += 1
            array[pos], item = item, array[pos]
            writes += 1
    return array, writes

if __name__ == "__main__":
    array = [random.randint(1, 1000) for _ in range(1000)]
    sorted_array, writes = cycle_sort(array)
    assert sorted_array == sorted(array)
