import xlwt

book = xlwt.Workbook()
sheet1 = book.add_sheet('sheet1')

def main():
    # print("i = ")
    # i = int(input())
    # print("e = ")
    # e = int(input())
    i = 2
    sheet1.write(0,1,"素朴法")
    sheet1.write(0,2,"二乗法")
    for e in range(2653):
        sheet1.write(e+1,0,e)
        bignum_pow1(i,e)
        bignum_pow2(i,e)

def bignum_pow1(b0, e):
    b1 = 1
    count = 0
    _e = e
    while e > 0:
        b1 *= b0
        e -= 1
        count += 1
    # print(b1)
    print("素朴法 count = "+str(count))
    sheet1.write(_e+1, 1, count)

def bignum_pow2(b0, e):
    b1 = 1
    count = 0
    _e = e
    while e > 0:
        if e%2 == 0:
            b0 *= b0
            e = int(e/2)
        else:
            b1 *= b0
            e -= 1
        count += 1
    # print(b1)
    print("二乗法 count = "+str(count))
    sheet1.write(_e+1, 2, count)

if __name__ == '__main__':
    main()
    book.save('test.xls')
