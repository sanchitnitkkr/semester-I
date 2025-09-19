# Write a program to check prime number using for loop
import math 

def isPrime(num):
    for i in  range(2,math.ceil(math.sqrt(num))):
        if(num%i == 0):
            return False 
        
    return True 

def main():
    num = int(input("Enter the number=> ").strip())
    if(isPrime(num)):
        print("Is prime")
    else :
        print("Isnt prime")
        
main()