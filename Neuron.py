import numpy as np
from sklearn.metrics import mean_squared_error 

class Neuron(object) :
	
	def __init__(self,n_feature=0,n_neurons=1) :
		np.random.seed(0)
		self.n_feature = n_feature
		self.n_neurons = n_neurons
		self.errors = []
		self.init_params()
		
	def init_params(self) :
		self.weights = np.random.randn(self.n_feature,self.n_neurons)
		self.bias = np.zeros((1,self.n_neurons))
		
	def brain_think(self,x) :
		return np.dot(x,self.weights) + self.bias
	 
	def mse(self,y,y_hat) :
		return (1/len(y))*np.sum(np.power((y- y_hat),2))
		
	def mse_deriv(self,y,y_hat) :
		 return (2/len(y)) *(y_hat - y)
		 
	def BackPropagation(self,x,y,alpha=0.01,epochs=100) :
		for i in range(epochs) :
			z = self.brain_think(x)
			dcdz = self.mse_deriv(y,z)
			dzdw = x.T
			dzdb = np.sum(dcdz)
			dcdw = np.dot(dzdw,dcdz)
			self.weights = self.weights - alpha * dcdw
			self.bias = self.bias - alpha*dzdb
		return "trained :)"
		
		
n = Neuron(2,n_neurons=1)
X = np.array([[1,1],[0,0],[1,0],[0,1]])
y = np.array([[1,1,0,0]]).T
print(n.BackPropagation(X,y,epochs=200,alpha=0.556))
y_hat = n.brain_think(X)
print(y_hat)
print(n.mse(y,y_hat))
print(mean_squared_error(y,y_hat))
print(n.brain_think(X[0]))