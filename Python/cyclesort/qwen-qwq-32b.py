

def cycleSort(array):
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
        writes +=1
        while pos != cycleStart:
            pos = cycleStart
            for i in range(cycleStart +1, n):
                if array[i] < item:
                    pos +=1
            while item == array[pos]:
                pos +=1
            array[pos], item = item, array[pos]
            writes +=1
    return writes

import sys
def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    cycleSort(arr)


if __name__ == "__main__":
    main()
