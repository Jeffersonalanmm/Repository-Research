
def beadsort(arr):
    if not arr:
        return []
    poles = [[x] for x in arr]
    n = len(poles)
    while True:
        moved = False
        new_poles = [pole.copy() for pole in poles]
        for i in range(n):
            if not poles[i]:
                continue
            bead = poles[i][-1]
            if i + 1 < n and bead > new_poles[i+1][-1]:
                # Move the bead to the next pole
                new_poles[i].pop()
                new_poles[i+1].append(bead)
                moved = True
        poles = new_poles
        if not moved:
            break
    # Now, extract the sorted array
    # The first pole will have the smallest elements at the top, but we need to collect all beads
    # Wait, no. Actually, the beads are distributed across the poles, with each pole's beads in increasing order from bottom to top.
    # So, to get the sorted array, we need to collect all beads from all poles, starting from the first pole's bottom to top, then the second's, etc.
    # Wait, no. Because each pole's beads are in order, with the smallest at the bottom and largest at the top.
    # So, the first pole has the smallest beads, but in reverse order. So, to get the sorted array, we need to collect the beads from each pole in reverse order.

    # Alternatively, perhaps the first pole will have the smallest bead at the bottom, and the last pole will have the largest at the top.
    # So, to get the sorted array, we need to collect all beads from all poles, starting from the first pole's bottom to top, then the second's, etc.

    # Wait, let me think. Suppose after sorting, the poles are arranged such that each pole's beads are in increasing order from bottom to top. So, the first pole has the smallest beads, and the last pole has the largest.

    # So, to get the sorted array, we need to collect all beads from all poles, starting from the first pole's bottom to top, then the second's, etc.

    # So, the sorted array is the concatenation of each pole's beads in reverse order.

    # For example, if poles are:
    # pole 0: [1,3,5]
    # pole 1: [2,4]
    # pole 2: [6]
    # Then the sorted array would be [1,2,3,4,5,6]

    # So, to collect this, we can iterate through each pole and extend the result list with the reversed pole.

    result = []
    for pole in poles:
        if pole:
            result.extend(reversed(pole))
    return result

