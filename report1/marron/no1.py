import math
import time
import subprocess
from subprocess import PIPE
import split8

def run_command(input):
    cmd = "Test.exe"
    with subprocess.Popen(cmd, shell=True, stdin=PIPE, stdout=PIPE, stderr=PIPE, universal_newlines=True) as pipe:
        out, err = pipe.communicate(input)
    return out

def make(opt):
    subprocess.run("make opt={}".format(opt), shell=True)
    return

def test_1_01_1():
    # 値チェック
    inputs = ["2 1 00000001\n10", "2 99999999 99999999\n10", "1 3\n100", "1 67108864\n78"]
    theorys = []
    print("1_01_1_check")
    with open("csv\\check_pow2.csv", mode="w") as output:
        make(0)
        for input in inputs:
            theorys.append(run_command(input).splitlines()[-1].rstrip())
        make(1)
        for i, input in enumerate(inputs):
            output.write(input.replace("\n", " ")+",")
            out = run_command(input).splitlines()[-1].rstrip()
            if out == theorys[i].rstrip():
                output.write("OK\n")
            else:
                output.write("NG\n")
                return
    # 計算範囲
    print("1_01_1_area")
    with open("csv\\1_01_1_area.csv", mode="w") as output:
        output.write("b1,theory,result\n")
        for b in range(2, 31):
            b1 = "1 {}\n".format(b)
            theory = int(800//math.log10(b))
            for e in range(theory-100,theory+2):
                #print(split8.split8_format(b**e))
                out = run_command(b1+str(e)).splitlines()[-1].rstrip()
                #print(out)
                if out == split8.split8_format(b**e).rstrip():
                    continue
                else:
                    output.write("{},{},{}\n".format(b,theory,e-1))
                    break
    return

def test_1_01_2():
    make(2)
    # 値チェック
    inputs = ["2 1 00000001\n10", "2 99999999 99999999\n10", "1 3\n100", "1 67108864\n78"]
    theorys = [100000001**10, 9999999999999999**10, 3**100, 67108864**78]
    print("1_01_2_check")
    with open("csv\\check_pow3.csv", mode="w") as output:
        for i, input in enumerate(inputs):
            output.write(input.replace("\n", " ")+",")
            out = run_command(input).splitlines()[-1].rstrip()
            if out == split8.split8_format(theorys[i]).rstrip():
                output.write("OK\n")
            else:
                output.write("NG\n")
                return
    # 計算範囲
    print("1_01_2_area")
    with open("csv\\1_01_2_area.csv", mode="w") as output:
        output.write("b1,theory,result\n")
        for b in range(2, 31):
            b1 = "1 {}\n".format(b)
            theory = int(800//math.log10(b))
            for e in range(theory-100,theory+2):
                #print(split8.split8_format(b**e))
                out = run_command(b1+str(e)).splitlines()[-1].rstrip()
                #print(out)
                if out == split8.split8_format(b**e).rstrip():
                    continue
                else:
                    output.write("{},{},{}\n".format(b,theory,e-1))
                    break
    # 計算回数
    print("1_01_2_count")
    with open("csv\\1_01_2_count.csv", mode="w") as output:
        output.write("func,count\n")
        for i in [0, 1, 2]:
            make(i)
            for input in inputs:
                out = run_command(input).splitlines()[-2].rstrip()
                output.write("pow{},{}\n".format(i+1, out))
    # 性能評価
    print("1_01_2_time")
    with open("csv\\1_01_2_time.csv", mode="w") as output:
        output.write("func,count,time\n")
        for mode in [0, 1, 2]:
            make(mode)
            for i in [10, 100, 1000]:
                start = time.time()
                for j in range(0,i):
                    out = run_command(inputs[0])
                end = time.time() - start
                output.write("pow{},{},{}s\n".format(mode+1, i, end))
    return

def test_1_03_1():
    # 値チェック
    print("1_03_1_check")
    n1 = (2**560)+(2**21)
    n2 = 2**538
    make(3)
    input = "{}\n{}".format(split8.split8(n1), split8.split8(n2))
    out = run_command(input)
    quo = out.splitlines()[-2].rstrip()
    rem = out.splitlines()[-1].rstrip()
    make(4)
    out = run_command(input)
    if out.splitlines()[-2].rstrip() == quo and out.splitlines()[-1].rstrip() == rem:
        print("OK")
    else:
        print("NG")
        return
    # 性能評価
    print("1_03_1_time")
    with open("csv\\1_03_1_time.csv", mode="w") as output:
        output.write("func,count,time\n")
        for mode in [3 ,4]:
            make(mode)
            for i in [10, 100, 1000]:
                start = time.time()
                for j in range(0,i):
                    out = run_command(input)
                end = time.time() - start
                output.write("div{},{},{}s\n".format(mode-3, i, end))
    return

def test_1_03_2():
    # 値チェック
    print("1_03_2_check")
    n1s = [2**651, 2**1023]
    n2s = [14352133, 2**23+1]
    make(5)
    for n1, n2 in zip(n1s, n2s):
        input = "{}\n{}".format(split8.split8(n1), split8.split8(n2))
        quo = split8.split8_format(n1//n2)
        rem = split8.split8_format(n1%n2)
        out = run_command(input)
        if out.splitlines()[-2].rstrip() == quo and out.splitlines()[-1].rstrip() == rem:
            print("OK")
        else:
            print("NG")
            return
    # 性能評価
    print("1_03_2_time")
    input = "{}\n{}".format(split8.split8(n1s[0]), split8.split8(n2s[0]))
    with open("csv\\1_03_2_time.csv", mode="w") as output:
        output.write("count,time\n")
        for i in [10, 100, 1000]:
            start = time.time()
            for j in range(0,i):
                out = run_command(input)
            end = time.time() - start
            output.write("{},{}s\n".format(i, end))
    return

def test_1_04_1():
    # 値チェック
    print("1_04_1_check")
    n1 = 2**1023
    n2 = 2**345-1
    make(6)
    input = "{}\n{}".format(split8.split8(n1), split8.split8(n2))
    quo = split8.split8_format(n1//n2)
    rem = split8.split8_format(n1%n2)
    out = run_command(input)
    if out.splitlines()[-2].rstrip() == quo and out.splitlines()[-1].rstrip() == rem:
        print("OK")
    else:
        print("NG")
        return
    return

def test_1_04_2():
    # 値チェック
    print("1_04_2_check")
    n1 = 2**1023
    n2 = 2**345-1
    make(6)
    input = "{}\n{}".format(split8.split8(n1), split8.split8(n2))
    out = run_command(input)
    quo = out.splitlines()[-2].rstrip()
    rem = out.splitlines()[-1].rstrip()
    make(7)
    out = run_command(input)
    if out.splitlines()[-2].rstrip() == quo and out.splitlines()[-1].rstrip() == rem:
        print("OK")
    else:
        print("NG")
        return
    # 性能評価
    print("1_04_2_time")
    with open("csv\\1_04_2_time.csv", mode="w") as output:
        output.write("func,count,time\n")
        for mode in [6 ,7]:
            make(mode)
            for i in [10, 100, 1000]:
                start = time.time()
                for j in range(0,i):
                    out = run_command(input)
                end = time.time() - start
                output.write("div{},{},{}s\n".format(mode-3, i, end))
    return

def test_1_05_1():
    make(8)
    a = (2**138-134521)*(2**364+9999)
    b = (2**138-134521)*(2**612+777)
    input = split8.split8(a)
    input += "\n"
    input += split8.split8(b)
    # 値チェック
    print("1_05_1_check")
    out = run_command(input).splitlines()[-1].rstrip()
    #print(out)
    #print(split8.split8_format(math.gcd(a, b)).rstrip())
    if out == split8.split8_format(math.gcd(a, b)).rstrip():
        print("OK")
    else:
        print("NG")
        return
    # 性能評価
    print("1_05_1_time")
    with open("csv\\1_05_1_time.csv", mode="w") as output:
        output.write("count,time\n")
        for i in [10, 100, 1000]:
            start = time.time()
            for j in range(0,i):
                out = run_command(input)
            end = time.time() - start
            output.write("{},{}s\n".format(i, end))
    return

def test_1_05_2():
    make(9)
    a = (2**138-134521)*(2**364+9999)
    b = (2**138-134521)*(2**612+777)
    input = split8.split8(a)
    input += "\n"
    input += split8.split8(b)
    # 値チェック
    print("1_05_2_check")
    out = run_command(input).splitlines()[-1].rstrip()
    #print(out)
    #print(split8.split8_format(math.gcd(a, b)).rstrip())
    if out == split8.split8_format(math.gcd(a, b)).rstrip():
        print("OK")
    else:
        print("NG")
        return
    # 性能評価
    print("1_05_2_time")
    with open("csv\\1_05_2_time.csv", mode="w") as output:
        output.write("count,time\n")
        for i in [10, 100, 1000]:
            start = time.time()
            for j in range(0,i):
                out = run_command(input)
            end = time.time() - start
            output.write("{},{}s\n".format(i, end))
    return

if __name__ == '__main__':
    test_1_01_1()
    test_1_01_2()
    #test_1_03_1()
    #test_1_03_2()
    test_1_04_1()
    test_1_04_2()
    test_1_05_1()
    test_1_05_2()