# Program to count the number of vowels in a string using loop

def getVowelCount(str):
    str = str.lower()
    vowelCount = 0
    
    for i in str:
        if(i in ["a", "e", "i", "o", "u"]):
            vowelCount+=1
    
    return vowelCount
    
def main():
    inputStr = input("Enter the string => ")
    vowelCount = getVowelCount(inputStr)
    print("The string",inputStr, "has", vowelCount, "vowels")
        
main()