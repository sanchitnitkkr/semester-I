# WAP that scripts to generate two arrays and performs element wise addition, subtraction and multiplication using broadcasting
import numpy as np

arr1 = np.array(range(0,5))
arr2=  np.array(range(5,10))

print("Current Arrays:")
print("Array 1 =>",arr1)
print("Array 2 =>",arr2)

result1 = arr1 + arr2 # Adds corresponding elements 
print("Addition Result =>",result1)

result2 = arr1 * arr2 # Multiplies corresponding elements 
print("Multiplication Result =>",result2)

result3 = arr1 - arr2 # Subtracts corresponding elements
print("Subtraction Result =>",result3)

result4 = arr1 / arr2 # Divides corresponding elements
print("Division Result =>",result4)


