def cycle_sort(arr):
    n = len(arr)
    writes = 0

    for i in range(n):
        if arr[i] == i + 1:
            continue  # Element already in correct position

        # Start a new cycle
        cycle_start = i
        val = arr[i]
        cycle_length = 0

        # Follow the cycle to determine its length
        while True:
            next_pos = val - 1
            if next_pos == cycle_start:
                break
            val = arr[next_pos]
            cycle_length += 1

        # Rotate the cycle
        if cycle_length > 0:
            temp = arr[cycle_start]
            for j in range(cycle_start, cycle_start + cycle_length):
                next_j = j + 1 if j < cycle_start + cycle_length - 1 else cycle_start
                arr[j] = arr[next_j]
            arr[cycle_start + cycle_length] = temp
            writes += 1

    return arr

# Example usage with 1000 random inputs
import random

def main():
    # Generate a random array of 1000 integers
    random.seed(42)
    arr = [random.randint(1, 1000) for _ in range(1000)]
    expected = sorted(arr)
    cycle_sort(arr)
    assert arr == expected

if __name__ == "__main__":
    main()
