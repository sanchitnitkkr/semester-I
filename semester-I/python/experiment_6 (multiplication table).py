# Program to print multiplication table

def main():
    multiplicationNum = int(input("Enter the number whose multiplication table you want => "))
    multiplicationUptoN = int(input("Enter the number till you want the table => "))

    for i in range(0,multiplicationUptoN+1):
        print(multiplicationNum, "*", i, "=", i*multiplicationNum)
        
main()