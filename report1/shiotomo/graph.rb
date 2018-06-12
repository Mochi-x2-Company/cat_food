require 'gnuplot'

def graph(data1, data2)
  Gnuplot.open do |gp|
    Gnuplot::Plot.new(gp) do |plot|
      plot.terminal "eps"
      plot.output "kadai1.eps"
      plot.xlabel "b1"
      plot.ylabel "e"
      plot.xrange"[2:31]"
      plot.yrange"[0:3000]"

      plot.data << Gnuplot::DataSet.new(data1) do |ds|
        ds.with ="lines"
        ds.linewidth = 4
        ds.title = "実験の値"
      end
      plot.data << Gnuplot::DataSet.new(data2) do |ds|
        ds.with ="lines"
        ds.linewidth = 4
        ds.title = "理論値"
      end
    end
  end
end

def main
  data1 = Array.new(0)
  data2 = Array.new(0)
  data1[0] = 0
  data2[0] = 0
  data1[1] = 0
  data2[1] = 0
  n = 2
  File.open("result-kadai1-01.txt", "r") do |f|
    f.each_line do |line|
      data = line.rstrip.split(",")
      data1[n] = data[1].to_i
      n += 1
    end
  end

  n = 2
  File.open("theoretical_value1-01.txt", "r") do |f|
    f.each_line do |line|
      data = line.rstrip.split(",")
      data2[n] = data[1].to_i
      n += 1
    end
  end

  p data1
  p data2

  graph(data1, data2)
end

if __FILE__ == $0
  main
end
