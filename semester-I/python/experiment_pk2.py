# Create a 1D array from 0 to 9. Slice elements from undex 3 to 7 and set them to 0.

import numpy as np

# Create the array
myArr = np.array(range(0,10))

print("Current Array =>", myArr)

myArr[3:8] = 0

print("After Updation =>", myArr)




