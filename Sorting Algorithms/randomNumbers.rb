#----------------------------------------------------------------
# create 10k data sets
ten_k_random = Array.new(9999){ rand(1...1000000) }
tenRandom = File.open("10kRandom.txt", "w+") do |f|
	ten_k_random.each { |element| f.puts(element) }
end

ten_k_sorted = Array.new(9999){ rand(1...1000000) }
ten_k_sorted.sort! { |x, y| x <=> y }
tenSorted = File.open("10kSorted.txt", "w+") do |f|
	ten_k_sorted.each { |element| f.puts(element) }
end

ten_k_reverse = Array.new(9999){ rand(1...1000000) }
ten_k_reverse.sort! { |x, y| y <=> x }
tenReverse = File.open("10kReverse.txt", "w+") do |f|
	ten_k_reverse.each { |element| f.puts(element) }
end

identical10k = rand(1...1000000)
ten_k_identical = Array.new(9999){ identical10k }
tenIdentical = File.open("10kIdentical.txt", "w+") do |f|
	ten_k_identical.each { |element| f.puts(element) }
end

# create 20k data sets
twenty_k_random = Array.new(19999){ rand(1...1000000) }
twentyRandom = File.open("20kRandom.txt", "w+") do |f|
	twenty_k_random.each { |element| f.puts(element) }
end

twenty_k_sorted = Array.new(19999){ rand(1...1000000) }
twenty_k_sorted.sort! { |x, y| x <=> y }
twentySorted = File.open("20kSorted.txt", "w+") do |f|
	twenty_k_sorted.each { |element| f.puts(element) }
end

twenty_k_reverse = Array.new(19999){ rand(1...1000000) }
twenty_k_reverse.sort! { |x, y| y <=> x }
twentyReverse = File.open("20kReverse.txt", "w+") do |f|
	twenty_k_reverse.each { |element| f.puts(element) }
end

identical20k = rand(1...1000000)
twenty_k_identical = Array.new(19999){ identical20k }
twentyIdentical = File.open("20kIdentical.txt", "w+") do |f|
	twenty_k_identical.each { |element| f.puts(element) }
end

#create 40k data sets
forty_k_random = Array.new(39999){ rand(1...1000000) }
fortyRandom = File.open("40kRandom.txt", "w+") do |f|
	forty_k_random.each { |element| f.puts(element) }
end

forty_k_sorted = Array.new(39999){ rand(1...1000000) }
forty_k_sorted.sort! { |x, y| x <=> y }
fortySorted = File.open("40kSorted.txt", "w+") do |f|
	forty_k_sorted.each { |element| f.puts(element) }
end

forty_k_reverse = Array.new(39999){ rand(1...1000000) }
forty_k_reverse.sort! { |x, y| y <=> x }
fortyReverse = File.open("40kReverse.txt", "w+") do |f|
	forty_k_reverse.each { |element| f.puts(element) }
end

identical40k = rand(1...1000000)
forty_k_identical = Array.new(39999){ identical40k }
fortyIdentical = File.open("40kIdentical.txt", "w+") do |f|
	forty_k_identical.each { |element| f.puts(element) }
end

#create 80k data sets
eighty_k_random = Array.new(79999){ rand(1...1000000) }
eightyRandom = File.open("80kRandom.txt", "w+") do |f|
	eighty_k_random.each { |element| f.puts(element) }
end

eighty_k_sorted = Array.new(79999){ rand(1...1000000) }
eighty_k_sorted.sort! { |x, y| x <=> y }
eightySorted = File.open("80kSorted.txt", "w+") do |f|
	eighty_k_sorted.each { |element| f.puts(element) }
end

eighty_k_reverse = Array.new(79999){ rand(1...1000000) }
eighty_k_reverse.sort! { |x, y| y <=> x }
eightyReverse = File.open("80kReverse.txt", "w+") do |f|
	eighty_k_reverse.each { |element| f.puts(element) }
end

identical80k = rand(1...1000000)
eighty_k_identical = Array.new(79999){ identical80k }
eightyIdentical = File.open("80kIdentical.txt", "w+") do |f|
	eighty_k_identical.each { |element| f.puts(element) }
end

#----------------------------------------------------------------

