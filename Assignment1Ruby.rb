# Function 1
# Ask the user to type 3 lines (e.g., before going to the next line the user will hit the
# ’Enter’ key, etc.) on keyboard, and your program should save the lines to a file named "lines.txt".

   aFile = File.open("lines.txt", "a+") do |aFile|
   aFile.puts "Hello, My name is Douglas Calmes and I have a 3 questions for you!"
  
   puts "What is your name?"
     name = gets
     name = name.chomp
   aFile.puts("The Users name is #{name}.")
  
   puts "What is your Major in college?"
     college = gets
     college = college.chomp
   aFile.puts("#{name} is majoring in #{college}.")
  
   puts "What year are you currently?"
     year = gets
     year = year.chomp
   aFile.puts("#{name} is a #{year} in #{college}.")
  
   end

File.open("lines.txt").each do |line|
  puts line
 end
 
# Function 2
# Ask the user to type the name of a file. If the file contains “Perl” or “Python”,
# then print “The file is interesting”. If the file contains “Ruby” or “ruby”, then 
# print “The file is awesome”.  Otherwise, print "The file is boring".

   puts "Please enter the name of a file"
     userFile = gets
    
     if userFile.include? "Perl"
       puts "The file is interesting"
     elsif userFile.include? "Python"
       puts "The file is interesting"
     elsif userFile.include? "Ruby"
       puts "The file is awesome"
     elsif userFile.include? "ruby"
       puts "The file is awesome"
     else
     puts "The file is boring"
   end
   
# Function 3
# Print the string “The cube of x is y” 50 times while substituting x by numbers from
# 5 to 54 while y is x3.
 
   x = 4
   max = 55
   cubed = 0
  
   begin
     cubed = x ** 3
     puts("The cube of #{x} is #{cubed}")
     x += 1
   end while x < max
  
# Function 4
# Let the user pick a number (say x) between 10 and 20. Now your program attempts
# to guess the number x. In particular, in each attempt your program randomly makes 
# a guess y (between 10 and 20) and compares with x, and it continues doing this 
# until the correct number x is guessed (i.e. y = x). After each guess, display whether 
# the guess was “higher than” or “lower than” x. Also, report the total number of 
# attempts your program needs.
  
   ranNum = Random.new.rand(10..20)
   numGuess = 1
  
   puts "Please pick a number between 10 and 20"
     guess = gets.to_i
    
     while guess < 10 || guess > 20 do
       puts "Try a new number between 10 and 20"
       guess = gets.to_i
     end
     
   while guess != ranNum
     if guess < ranNum
       puts "I guessed #{ranNum}, but it is higher than your number"
       ranNum = Random.new.rand(10..20)
       numGuess += 1
     elsif guess > ranNum
       puts "I guessed #{ranNum}, but it is lower than your number"
       ranNum = Random.new.rand(10..20)
       numGuess += 1
     end 
   end
    
   puts ("It took me #{numGuess} guesses to get it right!")
    
# Function 5
# Go to http://www.textfiles.com/stories/ and check that this site hosts multiple
# stories while each story is in a textfile. Download a textfile of your choice, 
# which has atleast 1000 words, and save the file as story.txt. Your program needs 
# to read this file and process it to collect some statistics. In particular, report 
# the total number words in the story, the number of distinct words, the second-most 
# frequent word and its frequency.

   bFile = File.new("story.txt", "r")
   words = []
   freq = Hash.new(0)   
   
   bFile.each do |line|
     cWords = line.scan(/[\w']+/) 
     words += cWords
     cWords.each {|w| freq[w] += 1}
   end
   
   puts "The total number of words = #{words.size}"
   puts "The number of distinct words = #{freq.size}"
 
   sorted = freq.sort_by{|w,count| count}
   top2 = sorted.last(2)
  
   puts "The Second most frequent word is #{top2[0][0]}"   
   puts "The second most frequent is #{top2[0][1]}"  
   
  
  
   
   

  