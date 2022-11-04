def beforeAnySymbol(this_sym,index,array,any_symb_arr) :
	if index == len(array) - 1 :
		return 0
	if array[index+1] in any_symb_arr :
		return array[index+1]
	return 0

def romanToInt(roman) :
	integer = 0
	roman_symbols = {'I' : 1, 'V' : 5,"X" : 10, 'L':50, 'D' : 500, 'M' : 1000,'C':100}
	freq = {}
	symbols = roman_symbols.items()
	for k,v in roman_symbols.items():
		freq[k] = 0
	
	N = len(roman)
	i = 0
	while i < N  :
		char = roman[i]
		if char in roman_symbols :
			if char == 'I' :
				v = beforeAnySymbol(char,i,roman,'VX')
				if v :
					integer += roman_symbols[v] - 1
					i += 2
				else :
					integer += 1
					i += 1
			elif char == 'X' :
				v = beforeAnySymbol(char,i,roman,'LC')
				if v :
					integer += roman_symbols[v] - 10
					i += 2
				else :
					integer += 10
					i += 1
			elif char == 'C' :
				v = beforeAnySymbol(char,i,roman,'DM')
				if v :
					integer += roman_symbols[v] - 100
					i += 2
				else :
					integer += 100
					i += 1
			else :
				integer += roman_symbols[roman[i]]
				i += 1
				
	print(integer)
	print("\n\n")
	return integer

romanToInt("XIV")
romanToInt("MCMXCIV")
romanToInt("LVIII")