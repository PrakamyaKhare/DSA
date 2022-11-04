import numpy as np

class DNN :
	def __init__(obj,i,j,k) :
		np.random.seed(1)
		obj.wij = np.random.randn(i,j)
		obj.wjk = np.random.randn(j,k)
		
	def sigmoid(obj,y) :
		e = 2.7182818246
		return (1/(1+e**-y))
		
	def relu(obj,y) :
		return y if y > 0 else 0
		
	def feedForward(obj,x,w='ij') :
		if w == "ij" :
			return np.dot(x,obj.wij)
		elif w == 'jk' :
			return np.dot(x,obj.wjk)
		
	def backP(obj,x,y,ep,alp) :
		x = np.array(x)
		y = np.array(y)
		for _ in range(ep) :
			z = obj.feedForward(x)
			y_hat = obj.feedForward(z,'jk')
			error = y_hat - y
			error_h = np.dot(obj.wjk,error.T)
			obj.wij -= alp*np.dot(x.T,error_h.T)
			obj.wjk -= alp*np.dot(z.T,error)
		return "Trained :)"
		
	def think(obj,x):
		z = obj.feedForward(x)
		y = obj.feedForward(z,'jk')
		a = obj.relu(y)
		if a > 0 :
			print('it is that number ',a)
		else :
			print('it is not that number ',a)
		return a

x = [[1,1,1,0,0,1,0,0,1]]
y = [[7]]       
dnn = DNN(9,10,1)
hist = dnn.backP(x,y,1000,0.01)
print(hist)
new_x = [[1,0,1,0,0,0,3,6,8]]
dnn.think(x)
dnn.think(new_x)
dnn.think([[0,0,0,0,1,5,7,8,9]])