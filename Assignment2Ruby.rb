# Function 1
# Implement a simple grep function that takes a string x as input, and prints the lines
# of a file having any occurences of string x anywhere in a line. You need to do a simple 
# regular expression match after reading lines from a file. The output should also include 
# the line numbers.

puts "Please enter a word you would like to search for in the file!"
  string = gets
  File.open("gambino.txt").grep(/string/) do |line|
  if(line =~ /#{string}/)
    puts line
  end
end

# Function 2
# This function takes an array A of integers as the input and does the following: (a)
# Uses each method to print the cube of each element of A, (b) Uses each_slice method to 
# print the elements while printing 5 elements at a time, (c) Uses select method to find 
# the integers (in A) which are multiple of 3, (d) Uses map method to build a new array of 
# cubes of the elements of A, and (e) Uses inject method to find the product of all elements 
# of A. To test Function2, generate an array A of 31 random integers between 10 and 100, 
# and pass into Function2 as a parameter.

arrayA = [1,2,3,4,5,6,7,8,9,10]

# Each mehtod
puts "This is the each method!"
arrayA.each do |a|
  puts a ** 3
end

# Each_slice method
puts "I will now do the each_slice method ot print 5 elements at a time!"
arrayA.each_slice(5){|b| p b}

# Select method
puts "I will now show you every item that is a multiple of 3!"
puts arrayA.select{|c| c%3==0}

# Map method
puts "This is the map method!"
arrayA.map do |d|
  puts d ** 3
end

# Inject method
productA = arrayA.inject do |e, element|
  e * element
end
puts "The product of the elements in the array are #{productA}!"


# Function 3
# Function3A calculates the Fibonacci Series (Fn = Fn−1 + Fn−2) iteratively. Calculate
# all Fibonacci numbers (Fn) for n = 1 to 40 (if it takes long time, try until 35 or so). 
# Function3B calculates the same Fibonacci Series but using the recursion technique. 
# After implementing the above two functions, compare the computation time 
# (for doing the above calculation) using Ruby’s benchmark library, and also compare lines 
# of code between the two implementations.

# Fibonacci series
def fibonacciI( m )
  a = 0
  b = 1
  
  m.times do
    temp = a
    a = b
    b = temp + b
  end
  
  return a
end
  
m = 1

begin
  puts fibonacciI( m )
  m += 1
end while m < 20

# Fibonacci series using recursion
def fibonacciR( n )
  return n if n <= 1
  fibonacciR( n - 1) + fibonacciR( n - 2)
end

n = 1

begin
  puts fibonacciR( n )
  n += 1
end while n < 20

# Benchmark
require 'benchmark'

test = 35
Benchmark.bm do |x|
  x.report("fibonacciI") {fibonacciI(test)}
  x.report("fibonacciR") {fibonacciR(test)}
end

# Function 4
# The Tree class presented in the textbook (Day 2) chapter is interesting, but it does not
# allow you to specify a new tree with a clean user interface. Update the constructor and 
# all other methods to accomodate the creation of a tree using a Hash. The initializer should 
# accept a nested structure of Hashes. You should be able to specify a tree as below. To test 
# your functionality, you should traverse this entire tree and print out the contents.

class Tree < Struct.new(:name, :children)
  def self.hashTree(hash)
    name, childHash = hash.first
    children = childHash.map { |w, e| Tree.hashTree({w => e}) }
    Tree.new(name, children)
  end

  def visit_all(&block)
    yield(self)
    children.each { |c| c.visit_all(&block) }
  end
end

familyTree = Tree.hashTree({
  'ggrandpa' => {
    'grandpa1' =>
      {'parent1' => {'child 1' => {}},
       'parent2' => {'child 2' => {}, 'child 3' => {}},
      },
    'grandpa2' => {'parent3' => {'child 4' => {}},
                   'parent4' => { 'child 5' => {}, 'child 6' => {}}}
                },
})

familyTree.visit_all { |x| puts x.name }

# Function 5
# In this task, your code creates a random list of 100 shape objects, then traverses the list
# from start to end, and computes the total area of the shape objects. First you need to implement 
# the class hierarchy diagram of the shape types, which is attached. Shape is an abstract class 
# which has only a "color" attribute whereas Circle class and Rectangle class are concrete children 
# of Shape class, and they have more attributes and constructors. Note that you do not know beforehand 
# the order of the shape objects (i.e. Circles and Rectangles) created in the random list, e.g. you 
# do not know beforehand whether the 1st item is Circle or Rectangle.

class Shape
 attr_accessor :color
 def initialize(color) 
  @color = color 
 end 
end

class Circle < Shape
  attr_accessor :area 
  def initialize (area) 
    super
     @area = rand(20)
     @color = "Green"

    end
  end 
class Rectangle < Shape
    attr_accessor :area
	def initialize (area)
       super 
	   @area = rand(20)
	   @color = "Purple"
   end
end

shapeA = [] 
  for i in 0..100
   toss = rand(2)
    if toss == 0
    r = Rectangle.new(50 * rand) 
    shapeA.push(r)
    else
    c = Circle.new(50 * rand)
    shapeA.push(c)
  end
end

shapeA.each{|item| puts item.area}
shapeA.each{|item| puts item.color}

sum = shapeA.inject(0){|sum, item| sum + item.area}

puts "The total area is #{sum}"