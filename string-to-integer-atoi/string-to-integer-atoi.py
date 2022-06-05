class Solution:
    def myAtoi(self, s: str) -> int:
        tmp = "0"
        number_started = False
        sign = 1
        
        for a in s:
            if number_started == False and a == " ":
                pass
            elif number_started == False and a == "+":
                number_started = True
                sign = 1
            elif number_started == False and a == "-":
                number_started = True
                sign = -1
            elif number_started == False and a.isdigit():
                number_started = True
                tmp = tmp + a
            elif number_started == False and a not in "+- " and not(a.isdigit()):
                break
            elif number_started == True and a.isdigit():
                tmp = tmp + a
            elif number_started == True and not(a.isdigit()):
                break
                
        
        if (sign * int(tmp)) < -(2**31):
            return -(2**31)
        elif (sign * int(tmp)) > ((2**31) - 1):
            return ((2**31) - 1)
        elif -(2**31) <= (sign * int(tmp)) <= ((2**31) - 1):
            return sign*int(tmp)

        
        