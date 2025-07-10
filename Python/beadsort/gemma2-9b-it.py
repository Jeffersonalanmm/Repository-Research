
import random

def beadsort(arr):
  max_val = max(arr)
  num_beads = max_val + 1
  beads = [0] * num_beads

  for num in arr:
    beads[num] += 1

  i = 0
  for j in range(num_beads):
    while beads[j] > 0:
      arr[i] = j
      beads[j] -= 1
      i += 1

  return arr

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = []
            for line in f:
                line = line.strip()
                if line.isdigit():
                    val = int(line)
                    if val >= 0:
                        arr.append(val)
    except FileNotFoundError:
        return

    beadsort(arr)
if __name__ == "__main__":
    main()

