# WAP a Numpy program to sort an array and find its minimum and maximum values.
import numpy as np

myArr = np.array(list(map(int,input("Please enter comma separated values => ").strip().split(','))))

print(myArr)
# Sort the array
myArr.sort()
print("Sorted Array =>", myArr)

# Minimum value
print("Minimum Value =>",myArr.min())

# Maximum value
print("Maximum Value =>", myArr.max())