# encoding: utf-8

before = Time.now.getutc

def isPrime(n)

	if n == 1
		return true
	end

	for i in 2..(Math.sqrt(n)) do
		if n % i == 0
			return false
		end
	end

	return true

end

def genPrimeRange(n)

	array = []

	for i in 2...n do
		if isPrime(i)
			array.push(i)
		end
	end

	return array

end

def getDivisors(n)

	array = []

	if isPrime(n)
		array.push(n)
	else

		genPrimeRange(n).each do |e|
			while n % e == 0
				array.push(e);
				n /= e
			end
		end

	end

	return array

end

def getArrayDivisors(n)

	array = []

	for i in 2..n do
		array.push(getDivisors(i))
	end

	return array
	
end

def genExpressionArray(n)

	array = []


	getArrayDivisors(n).each do |e|

		temp = []

		array.each do |a|
			temp.push(a)
		end

		e.each do |k|
			if findOnArray(temp, k)
				temp.delete_at(findOnArray(temp, k))
			else
				array.push(k)
			end
		end

	end

	return array
	
end

def findOnArray(array, key)

	counter = 0

	array.each do |e|
		if e == key
			return counter
		end
		counter += 1
	end

	return false

end

def multiplieValues(array)

	result = 1

	array.each do |e|
		result *= e
	end

	return result
	
end

def smallestMultiples(n)
	x = genExpressionArray(n)

	return multiplieValues(x)
end


puts smallestMultiples(20)


after = Time.now.getutc

puts "Runtime = "+(after - before).to_s+" seconds."