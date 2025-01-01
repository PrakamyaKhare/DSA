import matplotlib.pyplot as plt

def plot_data(X,Y,xlabel='x',ylabel='y') :
    plt.hist(Y,X)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.show()

def fetch_pos(array,elements :list[any]) :
    positions = []
    offset = 0
    for element in elements :
        for n in range(offset,len(array)) :
            if array[n] == element :
                if not array[n] in positions :
                    offset = n
                    positions.append(n)
    return positions

def xrange(a,b,step=0.1) :
    X = []
    while a <= b :
        X.append(a)
        a = a + step
    return X


def random_probability(X,y,a,b) :
    if type(y) == type([1]) :
        pos = fetch_pos(Y,[a,b])
        if len(pos) < 2 :
            print('error expected 2 values but got 1 :- ',pos, ' a = ',a,' b = ',b)
            return
        pos_a = pos[0]
        pos_b = pos[1]
        width = X[1] - X[0]
        area = 0
        for n in range(pos_a,pos_b+1) :
            area = area + y[n]
        return area*width
    
def data_preprocessing(Data : str) :
    Data = Data.split()
    data = [float(value) for value in Data]
    data.sort()
    return data



str_X = "8.9 12.4 8.6 11.3 9.2 8.8 6.2 7.0 7.1 11.8 10.7 7.6 9.1 9.2 8.2 9.0 8.7 9.1 10.9 10.3 9.6 7.8 11.5 9.3 7.9 8.8 8.8 12.7 8.4 7.8 5.7 10.5 10.5 9.6 8.9 10.2 10.3 7.7 10.6 8.3 8.8 9.5 8.8 9.4"
Y = data_preprocessing(str_X)
X = xrange(1,44,step=0.5)
#plot_data(44,Y)
Probability = random_probability(X,Y,Y[0],max(Y))
print(random_probability(X,Y,10.3,max(Y))/Probability)
Data = "11.88 6.27 5.49 4.81 4.40 3.78 3.44 3.11 2.88 2.68 7.99 6.07 5.26 4.79 4.05 3.69 3.36 3.03 2.74 2.63 7.15 5.98 5.07 4.55 3.94 3.62 3.26 2.99 2.74 2.62 7.13 5.91 4.94 4.43 3.93 3.48 3.20 2.89 2.69 2.61"
Data = data_preprocessing(Data)
plot_data(40,Data)
X = xrange(1,40,0.5)
T = random_probability(X,Data,Data[0],Data[-1])
print(Data)
P = random_probability(X,Data,4.05,Data[-1])
data = [val for val in Data if val > 4.0]
T = sum(Data)*.5
sum_data = sum(data)
print(sum_data*0.5/T)