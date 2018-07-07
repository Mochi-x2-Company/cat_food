# このコードはPython 3向けです。くれぐれもPython 2なんかで動かさないように！

import random
import time
import subprocess
from subprocess import PIPE

LOOP = 1000

""" 外部プログラム実行 """
def run_command(input):
    cmd = "./Test"
    with subprocess.Popen(cmd, shell=True, stdin=PIPE, stdout=PIPE, stderr=PIPE, universal_newlines=True) as pipe:
        out, err = pipe.communicate(input)
    return out

""" 実行ファイル作成 """
def make():
    subprocess.run("make", shell=True)
    return

""" 半乱順列生成 """
def make_rand(count):
    datas = list(range(1024))
    text = ""
    for i in range(count):
        p1 = random.randint(0,1023)
        p2 = random.randint(0,1023)
        datas[p1], datas[p2] = datas[p2], datas[p1]
    text += "1024 "
    for data in datas:
        text += " {}".format(data)
    return text

""" 問題2-01"""
def test_2_01():
    make()
    with open("csv/2_01.csv", mode="w") as output:
        output.write("count,q_comp,m_comp,h_comp,q_swap,m_swap,h_swap,q_sec,m_sec,h_sec\n")
        for i in range(100, 1001, 100):
            comp = [0, 0, 0]
            swap = [0, 0, 0]
            sec = [0, 0, 0]
            for j in range(LOOP):
                random_data = make_rand(i)
                for mode in range(3):
                    input_data = "{} {}".format(mode, random_data)
                    start = time.time()
                    out = run_command(input_data).splitlines()
                    end = time.time() - start
                    comp[mode] += int(out[-1].split(' ')[0])
                    swap[mode] += int(out[-1].split(' ')[1])
                    sec[mode] += end
                print("\r{} : {:.1f}%".format(i, (j+1)/LOOP*100), end='')
            output.write("{},{},{},{},{},{},{},{},{},{}\n".format(
                        i,comp[0]//LOOP,comp[1]//LOOP,comp[2]//LOOP,
                        swap[0]//LOOP,swap[1]//LOOP,swap[2]//LOOP,
                        sec[0]/LOOP,sec[1]/LOOP,sec[2]/LOOP))
            print()
    return

""" 問題2-03"""
def test_2_03():
    make()
    with open("csv/2_03.csv", mode="w") as output:
        output.write("count,comp,swap,sec\n")
        for i in range(100, 1001, 100):
            comp = 0
            swap = 0
            sec = 0
            for j in range(LOOP):
                random_data = make_rand(i)
                input_data = "3 {}".format(random_data)
                start = time.time()
                out = run_command(input_data).splitlines()
                end = time.time() - start
                comp += int(out[-1].split(' ')[0])
                swap += int(out[-1].split(' ')[1])
                sec += end
                print("\r{} : {:.1f}%".format(i, (j+1)/LOOP*100), end='')
            output.write("{},{},{},{}\n".format(i,comp//LOOP,swap//LOOP,sec/LOOP))
            print()
    return

if __name__ == '__main__':
    test_2_01()
    test_2_03()