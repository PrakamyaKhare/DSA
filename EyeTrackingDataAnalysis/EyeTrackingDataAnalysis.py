def check_num(arr) :
    num = [str(i) for i in range(10)]
    for n in arr :
        for e in n :
            if not e in num :
                return False
    return True

def remove_empty_elements(line) :
    line = line.split(',')
    cleaned_line = []
    for i in range(len(line)) :
        if line[i] :
            cleaned_line.append(line[i])
            continue
    return cleaned_line

def arr_to_str(arr) :
    string = ''
    for i in range(len(arr)) :
        if i == len(arr) - 1 :
            string += str(arr[i])
            break
        string += str(arr[i]) + ','
    return string

def check_line(line) :
    cleaned_line = remove_empty_elements(line) 
    if len(cleaned_line) == 4 :
        if cleaned_line[0] == 'MSG' and check_num(cleaned_line[1:]) :
            return 1
    return 0

def in_range(n1,n2,r) :
    if abs(n2-n1) <= 100 :
        return 1
    return 0

def check_coords(r1,r2) :
    if r1[0] == r2[0] and r1[1] == r2[1] :
        return 1
    return 0


# above functions are helper or utility functions
# reader should ignore the above functions

def clean_load_data(path) :
    file = open(path)
    data = file.read()
    file.close()
    dict_data = {}
    data = data.split('\n')
    i = 0
    N = len(data)
    D = 1
    while i < N :
        if check_line(data[i]) :
            dict_data["MSG_" + str(D)] = []
            r1 = remove_empty_elements(data[i])[2:]
            dict_data["MSG_"+str(D)].append(remove_empty_elements(data[i]))
            offset = 0
            another_msg = 0
            if check_line(data[i+1]) :
                r2 = remove_empty_elements(data[i+1])[2:]
                if not check_coords(r1,r2) :
                    i = i + 1
                    continue
                dict_data["MSG_"+str(D)][0].append(remove_empty_elements(data[i+1])[1])
                i = i + 1
            else :
                if remove_empty_elements(data[i+1])[0] == "EFIX" :
                    dict_data["MSG_"+str(D)].append(remove_empty_elements(data[i+1]))
                for j in range(i+2,N) :
                    if check_line(data[j]) :
                        r2 = remove_empty_elements(data[j])[2:4]
                        if not check_coords(r1,r2) :
                            i = j
                            another_msg = 1
                            break
                        dict_data["MSG_" + str(D)][0].append(remove_empty_elements(data[j])[1])
                        i = j
                        break
                if another_msg :
                    continue
            is_data = False
            for j in range(i+1,N) :
                if check_line(data[j]) or remove_empty_elements(data[j])[0] == "MSG":
                    is_data = True
                    i = j
                    break
                dict_data["MSG_"+str(D)].append(remove_empty_elements(data[j]))
                i = j
            D = D + 1
            i = i + 1
            if is_data :
                i = i - 1
            continue
        i = i + 1
    return dict_data

def process_data(path,threshold=2,r=50) :
    cleaned_data = clean_load_data(path)
    count_yes = 0
    for i in range(len(cleaned_data.keys())) :
        msg = cleaned_data['MSG_'+str(i+1)]
        x,y = float(msg[0][2]), float(msg[0][3])
        t = float(msg[0][1])
        to_consider = 0
        has_effix = 0
        xf,yf = 0,0
        for j in range(1,len(msg)) :
            if to_consider >= threshold :
                break
            if len(msg[j]) <= 1 :
                continue
            if msg[j][0] == "EFIX" and not has_effix :
                has_effix = 1
                xf,yf = float(msg[j][5]), float(msg[j][6])
            if msg[j][0] == "ESACC" and has_effix :
                to_consider = to_consider + 1
                xe,ye = float(msg[j][7]), float(msg[j][8])
                if in_range(xe,xf,r) and in_range(ye,yf,r) :
                    cleaned_data['MSG_'+str(i+1)][0].append("yes")
                    count_yes = count_yes + 1
                    t1,t2 = float(msg[j][2]), float(msg[j][3])
                    cleaned_data['MSG_'+str(i+1)][j].append(abs(t2-t1))
                    for k in range(j+1,len(msg)) :
                        if msg[k][0] == 'ESACC' :
                            xe,ye = float(msg[k][7]),float(msg[k][8])
                            t2 = float(msg[k][2])
                            if in_range(xe,x,r) and in_range(ye,y,r) :
                                cleaned_data['MSG_'+str(i+1)][0].append('yes')
                                cleaned_data['MSG_'+str(i+1)][k].append(abs(t2-t))
                                break
                    break
    print("No. of Data Points within range = ",count_yes)
    return cleaned_data
                
        

def save_data(data,path) :
    mega_string = ""
    for i in range(len(data.keys())) :
        msg = data["MSG_"+str(i+1)]
        for arr in msg :
            line = arr_to_str(arr)
            mega_string += line + '\n'
    file = open(path,'w')
    file.write(mega_string)
    file.close()
    return
 
path = "C:\\Users\\dell\\Downloads\\part_data.csv"
data = clean_load_data("C:\\Users\\dell\\Downloads\\part_data.csv")
print(data['MSG_3'])
print(len(data.keys()))
data1 = process_data(path)
save_data(data1,"C:\\Users\\dell\\Downloads\\mod_part_data.csv")
print(data1["MSG_1"])