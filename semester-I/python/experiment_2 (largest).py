# Q2) Program to find largest of three numbers (max fn and manually)


def largest(num1, num2, num3):
    if num1 >= num3 and num1 >= num2:
        return num1
    elif num2 >= num3 and num2 >= num1:
        return num2
    else:
        return num3


def takeInput():
    num1 = int(input("First num => "))
    num2 = int(input("Second num => "))
    num3 = int(input("Third num => "))

    return {"num1": num1, "num2": num2, "num3": num3}


inputData = takeInput()
largestViaCustomFn = largest(inputData["num1"], inputData["num2"], inputData["num3"])
largestViaInbuiltFn = max(inputData["num1"], inputData["num2"], inputData["num3"])

print(
    "The largest",
    "matches" if largestViaCustomFn == largestViaInbuiltFn else "does not match",
    "b/w inbuilt and custom fns ie", largestViaCustomFn
)