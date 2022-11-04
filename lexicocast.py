def index(word) :
	alpha = 'abcdefghijklmnopqrstuvwxyz'
	for ii in range(len(alpha)) :
		if word == alpha[ii] :
			return ii
			
	return None
	
def lexico(word) :
	words = word.split()
	update = []
	print(words[1])
	for ii in range(len(word)-1) :
		cur = index(words[ii][0])
		char = words[ii+1]
		nex = index(char[0])
		print(nex)
		if cur < nex :
			print('curr < n')
			update.append(words[ii])
			update.append(words[ii+1])
			print('b')
		else :
			print('v')
			update.append(words[ii+1])
			update.append(words[ii])
			print('x')
		print(update)
	return update
	
word = 'beta alpha'
a = lexico(word)
print(a)