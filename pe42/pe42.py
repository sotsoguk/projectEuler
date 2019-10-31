# ProjectEuler Problem 42:  Coded Triangle Numbers
#
# https://projecteuler.net/problem=42
#


def main():

    # load file, split into words and remove marks

    f = open('p042_words.txt')
    w = f.readline()
    w = w.split(",")
    words = []
    for i in w:
        words.append(i[1:-1])

    # compute alphanumeric values of each word

    values = []
    for word in words:
        v = sum(map(ord, word)) - 64 * len(word)
        values.append(v)

    # compute triangle numbers
    t = [1]
    for i in range(2, 30):
        t.append(t[-1]+i)

    tSet = set(t)

    # lookup each word whether it is a triangle number

    numSolutions = 0
    for v in values:
        if (v in tSet):
            numSolutions += 1

    print("PE42 Solution: {}".format(numSolutions))


if __name__ == "__main__":
    main()
