import math
# Program to check if a number is armstrong or not

def isArmstrong(num):
    result = 0
    original = num 
    
    
    while(num!=0):
        rem = num % 10
        result += math.pow(rem,math.floor(math.log10(original))+1)
        num = num//10
        
    return original == result 
    
def main():
    num = int(input("Enter the number => "))
    isArmstrongNum = isArmstrong(num)
    
    if(isArmstrongNum):
        print("Number is armstrong")
    else:
        print("Number is not armstrong")
        
main()