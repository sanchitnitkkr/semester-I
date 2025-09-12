from math import factorial

# Q5) Program to calculate factorial of a number (manually and inbuilt fn)


def customFactorial(N):
    result = 1
    for i in range(1, N+1):
        result *= i
    return result


def takeInput():
    N = int(input("Enter N => "))
    return N


N = takeInput()
customResult = customFactorial(N)
print("Custom factorial of", N, "is", customResult)
print("Inbuilt factorial of", N, "is", factorial(N))
