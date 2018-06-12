2.upto(31) do |n|
  log = (800 / Math.log10(n)).to_i
  puts "#{n}, #{log}"
  File.open("theoretical_value1-01.txt", "a") do |f|
    f.puts "#{n}, #{log}"
  end
end
