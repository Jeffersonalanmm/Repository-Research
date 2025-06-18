import random

random.seed(42)  # For reproducibility

def generate_random_list(size):
    return [random.randint(0, 100) for _ in range(size)]

# Test with 1000 random inputs
for _ in range(1000):
    data = generate_random_list(random.randint(1, 5))
    sorted_data = bogo_sort(data.copy())
    assert is_sorted(sorted_data)
