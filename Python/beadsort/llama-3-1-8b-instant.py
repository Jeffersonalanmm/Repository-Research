
class BeadSort:
    def __init__(self, beads):
        self.beads = beads
        self.max_value = max(beads)
        self.sorted_beads = [0] * (self.max_value + 1)

    def sort(self):
        for bead in self.beads:
            self.sorted_beads[bead] += 1

        for i in range(1, len(self.sorted_beads)):
            self.sorted_beads[i] += self.sorted_beads[i - 1]

    def get_sorted_beads(self):
        sorted_beads = [0] * len(self.beads)
        for i in range(len(self.beads)):
            sorted_beads[self.sorted_beads[self.beads[i]] - 1] = self.beads[i]
            self.sorted_beads[self.beads[i]] -= 1
        return sorted_beads


# Test the implementation with 1000 random inputs
import random

beads = [random.randint(0, 1000) for _ in range(1000)]
bead_sort = BeadSort(beads)
bead_sort.sort()
sorted_beads = bead_sort.get_sorted_beads()

