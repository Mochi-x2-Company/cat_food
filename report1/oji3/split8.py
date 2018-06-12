"""引数に渡した数字を8桁区切りにして返却します"""
def split8(num):
    out = ""
    num = str(num)[::-1]
    v = [num[i: i+8] for i in range(0, len(num), 8)]
    v.reverse()
    out += str(len(v))
    for i in v:
        out += " "
        out += str(i[::-1])
    return out

"""引数に渡した数字を8桁区切りにして返却します(format済み)"""
def split8_format(num):
    out = ""
    num = str(num)[::-1]
    v = [num[i: i+8] for i in range(0, len(num), 8)]
    v.reverse()
    out += "%3d :" % len(v)
    for no,i in enumerate(v):
        out += " "
        if no == 0:
            out += "%8d" % int(i[::-1])
        else:
            out += "%08d" % int(i[::-1])
    return out

if __name__ == "__main__":
    out = split8(2**100)
    print(out)