class Solution:
    
    def get_two_digit_word(self,n) :
        if n == '00' :
            return ""
        if n in ['11','12'] :
            return self.words[n]
        self.spelling = {'2' : 'Twen','3' : 'Thir','4':'For','5':'Fif','6':'Six','7':'Seven','8':'Eigh','9':'Nine'}
        if n[0] == '1' :
            return self.spelling[n[1]] + 'teen'
        if n[1] == '0' :
            return self.spelling[n[0]] + 'ty'
        return self.spelling[n[0]] + 'ty' + ' ' + self.words[n[1]]
    
    def remove_left_space(self,string) :
        N = len(string) - 1
        pos = N
        new_string = ''
        for n in range(N,-1,-1) :
            if string[n] == ' ' :
                continue
            for k in range(n+1) :
                new_string += string[k]
            break
        return new_string
    

    
    def number_to_words(self,n) :
        self.digits = {6: 'Million',3:'Thousand',2:'Hundred'}
        count_digit = len(n[1:])
        words = ""
        if count_digit in [6,7] :
            if count_digit == 7 :
                words = words + self.get_two_digit_word(n[:2])
            else :
                words = words + self.words[n[0]]
            words = words +' '+ self.digits[6] + ' '
            words = words + self.number_to_words(n[1:4]) + ' ' + self.digits[3] + ' ' + self.number_to_words(n[4:])
        elif count_digit in [3,4] :
            if count_digit == 4 :
                words = words + self.get_two_digit_word(n[:2])
            else :
                words = words + self.words[n[0]]
            words = words + ' ' + self.digits[3] + " " + self.number_to_words(n[1+(count_digit-3):])
        elif count_digit == 2 :
            words = words + self.words[n[0]] + ' ' + self.digits[2] + ' ' + self.get_two_digit_word(n[1:])
        else :
            return self.get_two_digit_word(n)
        return self.remove_left_space(words)

    
    def numberToWords(self, num: int) -> str:
        num = str(num)
        self.words = {'0':'','1':'One','2':'Two','3':'Three','4':'Four','5':'Five','6':'Six','7':'Seven','8':'Eight','9':'Nine','10':'Ten','11':'Eleven','12':'Twelve'}
        return self.number_to_words(num)
    
s = Solution()
print(s.numberToWords(233))