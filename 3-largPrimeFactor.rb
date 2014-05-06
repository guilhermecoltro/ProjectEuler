# encoding: utf-8

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

def getMaxFactorPrime(num)

	n = -1

	if isPrime(num)
		return "Este Número é Primo"
	end

	for i in 2..(Math.sqrt(num)) do
		if num % i == 0 
			if isPrime(i)
				n = i;
			end
		end
	end

	return n

end

numero = 600851475143

puts getMaxFactorPrime(numero)