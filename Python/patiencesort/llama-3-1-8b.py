
class PatienceSort:
    def __init__(self):
        self.stacks = []

    def sort(self, nums):
        for num in nums:
            inserted = False
            for i, stack in enumerate(self.stacks):
                if num >= stack[-1]:
                    self.stacks[i].append(num)
                    inserted = True
                    break
            if not inserted:
                self.stacks.append([num])
        return self._flatten()

    def _flatten(self):
        return [num for stack in self.stacks for num in stack]


# Test the implementation
patience_sort = PatienceSort()
numbers = [5, 2, 8, 1, 9, 3, 7, 6, 4, 0, 10, 15, 12, 18, 14, 11, 13, 16, 17, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100]
sorted_numbers = patience_sort.sort(numbers)
