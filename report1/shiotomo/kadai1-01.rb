# 問題1-01用
require "open3"

def expr1_01(n, log)
  flag = true
  File.open("kadai1.txt", "a") do |f|
    Open3.popen3("./BigNum/TestMlt") do |stdin, stdout, stderr, status|
      stdin.puts "1 1 #{n} #{log}"
      stdin.close
      # puts "== stdout"

      puts "1 1 #{n} #{log}"
      exit_status = status.value.to_s.split(" ")

      puts exit_status[3]
      if exit_status[3] != "0"
        flag = false
        expr1_01(n, log - 1)
      end

      if flag
        File.open("result-kadai1-01.txt", "a") do |file|
          file.puts "#{n}, #{log}"
        end
        f.puts "1 1 #{n} #{log}"
        # 標準出力の最初の7行を飛ばす
        n = 0
        stdout.each do |line|
          n += 1
          next if n < 8
          puts line
          f.puts line
        end
        f.puts ""
      end
    end
  end
end

def main
  2.upto(31) do |n|
    log = (800 / Math.log10(n)).to_i
    expr1_01(n, log)
  end
end

if __FILE__ == $0
  main
end
