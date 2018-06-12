import math
import subprocess
from subprocess import PIPE
import split8

def run_command(cmd, input):
    with subprocess.Popen(cmd, shell=True, stdin=PIPE, stdout=PIPE, stderr=PIPE, universal_newlines=True) as pipe:
        out, err = pipe.communicate(input)
    return out

def test_1_01_1():
    # 値チェック
    with open("check_pow2.txt", mode="w") as output:
        inputs = ["2 1 00000001\n10", "2 99999999 99999999\n10", "1 3\n100", "1 67108864\n78"]
        theorys = [100000001**10, 9999999999999999**10, 3**100, 67108864**78]
        for i, input in enumerate(inputs):
            out = run_command("Test.exe", input).splitlines()[0].rstrip()
            if out == split8.split8_format(theorys[i]).rstrip():
                output.write("OK\n")
            else:
                output.write("NG\n")
    # 計算範囲
    with open("1_01_1.csv", mode="w") as output:
        output.write("b1,理論値,結果\n")
        for b in range(2, 31):
            b1 = "1 {}\n".format(b)
            theory = int(800//math.log10(b))
            for e in range(theory-3,theory+2):
                print(split8.split8_format(b**e))
                out = run_command('Test.exe', b1+str(e)).splitlines()[0].rstrip()
                print(out)
                if out == split8.split8_format(b**e).rstrip():
                    continue
                else:
                    output.write("{},{},{}\n".format(b,theory,e-1))
                    break
    return

def test_1_01_2():
    # 値チェック
    # 計算範囲
    # 計算回数
    # 実行速度
    return

def test_1_05_1():
     = split8.split8()
    print(run_command("Test.exe", input))
    return

if __name__ == '__main__':
    #test_1_01_1()
    test_1_05_1()