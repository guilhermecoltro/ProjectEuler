# encoding: utf-8

before = Time.now.getutc

def genFibo(max)

	x = 1
	y = 2

	sum = y
	counter = 2

	while x < max && y < max
		if counter % 2 == 0
			x += y
			if x % 2 ==0
				sum += x
			end
		else
			y += x
			if y % 2 == 0
				sum += y
			end
		end

		counter += 1
	end

	return sum

end

puts genFibo(4000000)

after = Time.now.getutc

puts "Execution Time = "+(after - before).to_s+" seconds."