class Solution:
    
    def __init__(self,) :
        self.alphabets = 'abcdefghijklmnopqrstuvwxyz'
        self.dict_alphabets = {}
        self.rev = {}
        for i in range(len(self.alphabets)) :
            self.dict_alphabets[self.alphabets[i]] = i+1
            self.rev[i+1] = self.alphabets[i]

    
    def compute_permutation(self,words) :
        permutations = []
        for i in range(len(words)) :
            for j in range(len(words)) :
                if i != j :
                    permutation = words[i] + words[j]
                    for k in range(len(words)) :
                        if k != j and k != i :
                            permutation += words[k]
                    permutations.append(permutation)
        return permutations
    
    def numerised_words(self,words ) :
        encoded = []
        for word in words :
            nums = []
            for alpha in word :
                nums.append(self.dict_alphabets[alpha])
            encoded.append(nums)
        return encoded
    
    def extract_words(self,st,i,f) :
        encoded = []
        for j in range(i,f) :
            encoded.append(self.dict_alphabets[st[j]])
        return encoded
    
    def equal(self,A,B) :
        for a,b in zip(A,B) :
            if a != b :
                return False
        return True
    
    def findSubstring(self, s: str, words) :
        permutations = self.compute_permutation(words)
        encoded = self.numerised_words(permutations)
        self.e = encoded
        P = len(permutations[0])
        offsets = []
        print(encoded)
        print('///')
        for i in range(len(s)) :
            if i+P == len(s) :
                break
            sub_encoded = self.extract_words(s,i,i+P)
            print(sub_encoded)
            for e in encoded :
                if self.equal(sub_encoded,e) :
                    offsets.append(i)
        return offsets
                
            
s = Solution()
g  = s.findSubstring("barfoofoobarthefoobarman"
,["bar","foo","the"])
print(g)
print(s.findSubstring("wordgoodgoodgoodbestword",
["word","good","best","good"]))