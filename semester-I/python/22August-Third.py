from utils import gap

# Operators in Python

# ARITHMETIC OPERATORS

a = 5
b = 10

# Addition
print(a+b) # 15

# Subtraction
print(a-b) # -5

# Multiplication
print(a*b) # 50

# Division
print(a/b) # 0.5

# Modulus
print(a%b) # 5

# Exponent
print(b**2) # 100

# Complete Division
print(50/3) # 16.666

gap()

# ASSIGNMENT OPERATORS
c = 120

# Increment
c+=2
print(c) # 122

# Decrement
c-=2
print(c) # 120

# Multiplication
c*=2
print(c) # 240

# Division
c/=2
print(c) # 120

# Modulus
c%=7
print(c) # 1

c=120

# Floor Division
c//=2
print(c)

# Exponent
c**=2   
print(c)

gap()

# COMPARSION OPERATORS
a,b,c = 20,30,40

print(a==b) # False
print(a!=b) # True
print(a>b) # False
print(a<b) # True
print(a>=b) # False
print(a<=b) # True

gap()

# LOGICAL OPERATORS
def largest(a,b,c):
    if(a>b and a>c):
        print('a is the largest')
    elif(b>a and b>c):
        print('b is the largest')
    else:
        print('c is the largest')

def validAge(age):
    if((age>18 and age<24) or (age<50 and age > 40)):
        return True
    return False

validAge(32)
largest(a,b,c)
gap()

# BITWISE OPERATORS
a = 5
b = 3

print(a & b) # BIT AND Operation
print(a|b) # BIT OR Operation
print(a^b) # BIT XOR Operation
print(~a) # Flips all bits
print(a<<2) # Shift bits towards the left
print(a>>2) # Shift bits towards the right
    
