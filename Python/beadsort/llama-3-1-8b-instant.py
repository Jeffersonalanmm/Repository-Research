
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


import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            beads = []
            for line in f:
                line = line.strip()
                if line.isdigit():
                    beads.append(int(line))
    except FileNotFoundError:
        return

    if not beads:
        return

    bead_sort = BeadSort(beads)
    bead_sort.sort()
    bead_sort.get_sorted_beads()


if __name__ == "__main__":
    main()
