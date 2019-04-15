# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
def sumLetters(n):
    lSum = 0
    for c in n:
        lSum += (ord(c) - 64)  # only capital letters are handled correctly
    return lSum

def main(argv):
    names = []
    queries = []
    numNames = int(input())
    for _ in range(0,numNames):
        names.append(str(input()))
    numQueries = int(input())
    for _ in range(0,numQueries):
        queries.append(str(input()))
    names.sort()
    for q in queries:
        idx = names.index(q)
        value = (idx+1) * sumLetters(q)
        print(value)
    # compute sum
    total = 0
    #for i, n in enumerate(names):
    #    total += (i+1) * sumLetters(n)

    #print("Solution to PE 20: ", total)
    pass


if __name__ == "__main__":
    main(sys.argv)