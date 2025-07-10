def gnome_sort(arr):

    i = 1

    n = len(arr)

    while i < n:

        if arr[i] < arr[i-1]:

            arr[i], arr[i-1] = arr[i-1], arr[i]

            i -=1

            if i <1:

                i =1

        else:

            i +=1

    return arr

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = gnome_sort(arr)
    
    print(sorted_arr)

if __name__ == "__main__":
    main()