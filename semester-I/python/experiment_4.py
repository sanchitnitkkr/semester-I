# Q4) Program to calculate area and perimeter of a rectangle

def perimeterRectangle(length,breadth):
    return length + breadth

def areaRectangle(length,breadth):
    return length * breadth

def takeInput():
    length = int(input("Length => "))
    breadth = int(input("Breadth => "))

    return {"length": length, "breadth": breadth}

inputData = takeInput()
perimeter = perimeterRectangle(inputData["length"], inputData["breadth"])
area = areaRectangle(inputData["length"], inputData["breadth"])

print("Perimeter of rectangle with length & breadth as", inputData["length"], inputData["breadth"], "respectively is", perimeter)
print("Area of rectangle with length & breadth as", inputData["length"], inputData["breadth"], "respectively is", area)
