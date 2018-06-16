def main():
    print("基数:",end='')
    i = input()
    print("べき乗:",end='')
    j = input()

    pre_figure = str(pow(int(i), int(j)))
    #pre_figure = "3773962424821541352241554580988268890916921220416440428376206300245624162392148852086126725177658767541468375030763844899770584629924792632561434251432696043649397424128"
    flen = len(str(pre_figure))

    rest = flen % 8

    print(str(flen) + ":", end=' ')

    print(pre_figure[0:rest], end=' ')

    prelen = flen/8

    for i in range(int(prelen)):
        print(pre_figure[rest:rest+8], end=" ")
        rest+=8

if __name__ == "__main__":
    main()