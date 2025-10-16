# Swap using tuples
# (a,b)= (1,2,)
# print(a)
# print(b)
# a,b = b,a
# print(a)
# print(b)

# a = int(input("First number => ").strip())
# b = int(input("Second number => ").strip())
# tuple1 = (a,b)
# list1 = list(tuple1)
# temp = list1[0]
# list1[0] = list1[1]
# list1[1] = temp 
# tuple1 = tuple(list1)
# print(f"a => {tuple1[0]} and b=> {tuple1[1]}")

a = int(input("First number => ").strip())
b = int(input("Second number => ").strip())
temp_tuple = (b,a)
a,b = temp_tuple
print(f"a => {a} and b=> {b}")