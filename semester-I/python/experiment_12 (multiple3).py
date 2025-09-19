# Write a program to print 1 to 30 numbers but skip multiple of 3

def skipMultipleOf3():
    for i in range(1,31):
        if(i%3==0):
            continue
        print(i,end=",")

def main():
    skipMultipleOf3()
    
main()