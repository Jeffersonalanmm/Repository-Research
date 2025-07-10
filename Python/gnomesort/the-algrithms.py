"""
Gnome Sort Algorithm (A.K.A. Stupid Sort)

This algorithm iterates over a list comparing an element with the previous one.
If order is not respected, it swaps element backward until order is respected with
previous element.  It resumes the initial iteration from element new position.

For doctests run following command:
python3 -m doctest -v gnome_sort.py

For manual testing run:
python3 gnome_sort.py
"""


def gnome_sort(lst: list) -> list:
    """
    Pure implementation of the gnome sort algorithm in Python

    Take some mutable ordered collection with heterogeneous comparable items inside as
    arguments, return the same collection ordered by ascending.

    Examples:
    >>> gnome_sort([0, 5, 3, 2, 2])
    [0, 2, 2, 3, 5]

    >>> gnome_sort([])
    []

    >>> gnome_sort([-2, -5, -45])
    [-45, -5, -2]

    >>> "".join(gnome_sort(list(set("Gnomes are stupid!"))))
    ' !Gadeimnoprstu'
    """
    if len(lst) <= 1:
        return lst

    i = 1

    while i < len(lst):
        if lst[i - 1] <= lst[i]:
            i += 1
        else:
            lst[i - 1], lst[i] = lst[i], lst[i - 1]
            i -= 1
            if i == 0:
                i = 1

    return lst


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
