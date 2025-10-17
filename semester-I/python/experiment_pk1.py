# Create a numpy array of numbers 1 to 12 and reshape it into at 3*4 matrix. Print its shape, ndim and size
import numpy as np

# Create the array
myArr = np.array(range(1,13))

# Current array shape
print("Old shape =>", myArr.shape) # Prints (12,) => This kind of output appears for only 1 dimensional array
print("Old ndim =>", myArr.ndim) # Prints (12,) => The number of dimensions
print("Old size =>", myArr.size) # Prints 12 => Number of elements

# Reshape it
myArr = myArr.reshape(3,4) # Reshape returns a View or copy 

print("======================")

# Updated array shape
print("New shape =>", myArr.shape) # Prints (12,) => This kind of output appears for only 1 dimensional array
print("New ndim =>", myArr.ndim) # Prints (12,) => The number of dimensions
print("New size =>", myArr.size) # Prints 12 => Number of elements




