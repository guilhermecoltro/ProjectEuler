# encoding: utf-8

before = Time.now.getutc

def checkPalind(n)

	if n % 11 != 0
		return false
	end

	s = n.to_s

	size = s.length % 2 == 0 ? s.length/2 : (s.length-1)/2

	for i in 0...size do
		if s[i] != s[(s.length-1)-i]
			return false
		end
	end

	return true

end

def genElevenRange(from, to)

	array = []

	for i in from..to do
		if i % 11 == 0
			array.push(i)
		end
	end

	return array

end

def largPalinProduct(dig)
	
	start = 10**(dig-1)
	stop  = 10**(dig) -1

	big = -1

	range = genElevenRange(start, stop)

	for i in start..stop do
		range.each do |e|
			if checkPalind(i*e) && i*e > big
				big = i*e
			end
		end
	end

	return big

end


puts largPalinProduct(3)

after = Time.now.getutc

puts "Execution Time = "+(after - before).to_s+" seconds."