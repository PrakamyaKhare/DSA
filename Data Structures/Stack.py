class Stack :

    def __init__(self,N) :
        self.front = -1
        self.back = -1
        self.N = N
        self.stack = []
    
    def is_full(self,) :
        if self.front == self.N :
            return True
        return False

    def is_empty(self,) :
        if self.front == -1 :
            return True
        return False
    
    def push(self,n) :
        if not self.is_full() :
            if not self.stack == [] :
                temp_stack = []
                temp_stack.append(n)
                for element in self.stack :
                    temp_stack.append(element)
                self.stack = temp_stack.copy()
                return
            self.stack.append(n)
            return


    def pop(self,) :
        if not self.is_empty() :
            temp_stack = []
            for k in range(1,len(self.stack)) :
                temp_stack.append(self.stack[k])
            self.stack = temp_stack.copy()
            return

stack = Stack(10)
elements = ["("*5] + [')'*5]
for element in elements :
    stack.push(element)
for s in stack.stack :
    print(s,' ',end='')