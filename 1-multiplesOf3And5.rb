# encoding: utf-8

before = Time.now.getutc

def multiples_of_3_and_5(n)

	sum = 0
	
	for i in 2...n
		if i % 3 == 0 || i % 5 == 0
			sum += i
		end
	end

	return sum

end

puts multiples_of_3_and_5(1000)

after = Time.now.getutc

puts "Execution Time = "+(after - before).to_s+" seconds."