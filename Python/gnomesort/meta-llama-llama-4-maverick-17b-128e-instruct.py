import random

def gnome_sort(nums):
    """
    Sorts a list of numbers using the Gnome Sort algorithm.

    Args:
        nums (list): A list of numbers to be sorted.

    Returns:
        list: A sorted list of numbers.
    """
    i = 1
    while i < len(nums):
        if nums[i-1] <= nums[i]:
            i += 1
        else:
            nums[i-1], nums[i] = nums[i], nums[i-1]
            if i > 1:
                i -= 1
    return nums

def generate_random_list(size):
    """
    Generates a list of random integers.

    Args:
        size (int): The size of the list.

    Returns:
        list: A list of random integers.
    """
    return [random.randint(0, 1000) for _ in range(size)]

if __name__ == "__main__":
    # Generate a list of 1000 random integers
    random_list = generate_random_list(1000)
    
    # Sort the list using Gnome Sort
    sorted_list = gnome_sort(random_list)