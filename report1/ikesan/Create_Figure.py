def main():
    print("基数:",end='')
    i = input()
    print("べき乗:",end='')
    j = input()

    pre_figure = pow(int(i), int(j))
    flen = len(str(pre_figure))

    

    print(flen, pre_figure)

if __name__ == "__main__":
    main()