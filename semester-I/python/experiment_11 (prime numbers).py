# Write a program for generating all prime numbers between two given numbers
import math 

ERRORS = {
    "NEGATIVE_NUMBER" : "Negative values are not allowed!",
    "RANGE_ERROR" : "Start Number cannot be more than end number"
}

class GenericException(Exception):
    def __init__(self, message="Some error occured"):
        super().__init__(message)


def isPrime(num):
    for i in range(2,math.ceil(math.sqrt(num))):
        if(num%i == 0):
            return False
    return True
    

def getAllPrimeNumbers(start, end):
    primeNumbers = []
    
    for i in range(start,end+1):
        if(isPrime(i)):
            primeNumbers.append(i)
    
    return primeNumbers

def main():
    while True:
        try:
          startNumber = int(input("Enter the start number: ").strip())
          endNumber = int(input("Enter the end number: ").strip())

          if(startNumber > endNumber):
            raise GenericException(ERRORS["RANGE_ERROR"])
        
          elif(startNumber < 0 or endNumber < 0):
            raise GenericException(ERRORS["NEGATIVE_NUMBER"])
        
          break
        except ValueError:
            print("Please enter a valid input")
        except GenericException as message:
            print(message)

    allPrimeNums = getAllPrimeNumbers(startNumber,endNumber)

    print("All prime nums are =>")
    print(allPrimeNums)

main()
