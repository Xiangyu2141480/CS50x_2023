import csv
import sys


def main():
    # Check command-line arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database into memory
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        for row in reader:
            database.append(row)

    # Read DNA sequence into memory
    with open(sys.argv[2]) as dna_file:
        dna = dna_file.read()

    # Compute longest run of consecutive STR repeats
    strs = database[0][1:]
    lengths = []
    for subseq in strs:
        longest = longest_match(dna, subseq)
        lengths.append(longest)

    # Check database for matching profiles
    for i in range(1, len(database)):
        person = database[i]
        matched = True
        for j in range(1, len(person)):
            if int(person[j]) != lengths[j - 1]:
                matched = False
                break
        if matched:
            print(person[0])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest = 0
    sublen = len(subsequence)
    for i in range(len(sequence)):
        count = 0
        while True:
            start = i + count * sublen
            end = start + sublen
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest = max(longest, count)
    return longest


main()
