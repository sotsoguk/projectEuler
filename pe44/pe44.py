# ProjectEuler Problem 44:  Pentagon Numbers
#
# https://projecteuler.net/problem=44
#


def main():

    # load file, split into words and remove marks

    # create pentagonal numbers
    limit = 10000
    pentNums = [1]
    for i in range(2, limit+1):
        pentNums.append(pentNums[-1]+3*i-2)
    pSet = set(pentNums)

    for i in range(1, limit):
        for j in range(1, i+1):
            summ = pentNums[i] + pentNums[j]
            diff = pentNums[i] - pentNums[j]
            if ((summ in pSet) and (abs(diff) in pSet)):
                print("{},{}".format(pentNums[i], pentNums[j]))
                print("D = {}".format(abs(diff)))


if __name__ == "__main__":
    main()
