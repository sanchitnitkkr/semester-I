import math 

def customGCD2(firstNum,secondNum):
    highest = 1
    
    for i in range(2,int(math.sqrt(min(firstNum,secondNum)))+1):
        if(firstNum % i == 0 and secondNum % i == 0):
            highest = max(highest, i, firstNum // i , secondNum // i)
            
    return highest
            
    
def customGCD(firstNum,secondNum):
    factors1Set = []
    factors2Set = []
    
    for i in range(1,int(math.sqrt(firstNum))+1):
        if(firstNum % i == 0):
            factors1Set.append(i)
            factors1Set.append(firstNum//i)
            
    for i in range(1,int(math.sqrt(secondNum))+1):
        if(secondNum % i == 0):
            factors2Set.append(i)
            factors2Set.append(secondNum//i)
            
    factors1Set.sort()
    factors2Set.sort()
    
    fp = 0
    sp = 0
    highest = -1
    
    while(fp<len(factors1Set) and sp<len(factors2Set)):
        if(factors1Set[fp] == factors2Set[sp]):
            highest = factors1Set[fp]
            fp+=1
            sp+=1
        elif(factors1Set[fp]>factors2Set[sp]):
            sp+=1
        else:
            fp+=1
    
    return highest
    
def main():
    firstNum = int(input("Enter the first num => "))
    secondNum = int(input("Enter the second num => "))
    gcd = customGCD2(firstNum,secondNum)
    print("GCD of",firstNum,"and",secondNum,"is",gcd)
        
main()

