import sys

# Sum the value of the capital letters
def sumLetters(n):
    lSum = 0
    for c in n:
        lSum += ( ord(c) - 64 ) # only capital letters are handled correctly
    return lSum

def main(argv):
    with open('input.txt') as f:
        lines = f.readlines()
    names = lines[0].split(',')
    names = [ n[1:-1] for n in names]
    names.sort()

    # compute sum
    total = 0
    for i, n in enumerate(names):
        total += (i+1) * sumLetters(n)
    
    print("Solution to PE 20: ", total)
    pass

if __name__ == "__main__":
    main(sys.argv)