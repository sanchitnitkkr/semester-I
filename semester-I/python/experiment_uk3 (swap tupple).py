# Swap using tuples
# (a,b)= (1,2,)
# print(a)
# print(b)
# a,b = b,a
# print(a)
# print(b)

a = int(input("First number => ").strip())
b = int(input("Second number => ").strip())
a,b = b,a
print("Numbers after swapping:")
print(f"a =>{a} and b=> {b}")