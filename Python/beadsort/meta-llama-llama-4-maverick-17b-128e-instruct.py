
import random

def beadsort(input_list):
    """Bead sort algorithm implementation."""
    # Create a 2D list to represent the beads
    beads = [[0 for _ in range(len(input_list))] for _ in range(max(input_list))]
    
    # Initialize the beads based on the input list
    for i, val in enumerate(input_list):
        for j in range(val):
            beads[j][i] = 1
    
    # Count the beads in each column
    counts = [sum(col) for col in zip(*beads)]
    
    # Update the input list with the sorted values
    for i, count in enumerate(counts):
        input_list[i] = count
    
    return input_list

def generate_random_input(n):
    """Generate a list of 'n' random integers."""
    return [random.randint(0, n) for _ in range(n)]

# Test the beadsort function with 1000 random inputs
input_list = generate_random_input(1000)
sorted_list = beadsort(input_list)

