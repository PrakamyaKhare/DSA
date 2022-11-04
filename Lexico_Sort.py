def get_pos(char) :
	alpha = 'abcdefghijklmnopqrstuvwxyz'
	pos = -1
	for i in alpha :
		pos = pos + 1
		if i == char.lower() :
			return pos

def lexico_sort(sort_arr) :
	
	dict_obj = {}
	names = {}
	
	for n,char in enumerate(sort_arr) :
		key = get_pos(char[0])
		key = str(key)
		
		if key in dict_obj.keys():
			val = dict_obj[key]
			
			if type(val) == type('a') :
				vals = []
				vals.append(val)
				vals.append(char)
				dict_obj[key] = vals
				continue
				
			val.append(char)
			dict_obj[key] = val
			continue
			
		dict_obj[key] = char
	
	nums = [int(i) for i in dict_obj.keys()]
	N = len(nums)
	
	for i in range(N) :
		is_sort = False
		for j in range(N-1) :
			if nums[j] > nums[j+1] :
				temp = nums[j]
				nums[j] = nums[j+1]
				nums[j+1] = temp
				is_sort = True
		if not is_sort :
			break
	
	sorted_names = []
	for n in nums :
		names = dict_obj[str(n)]
		if type(names) == type([1]) :
			for name in names :
				sorted_names.append(name)
			continue
		sorted_names.append(names)
		
	return sorted_names
	
names = ["Prakamya","sunny","ankit","jason","carlos","anuj"]

print(lexico_sort(names))