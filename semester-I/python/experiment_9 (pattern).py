
def printPattern(N):
    rows = N

    for i in range(0,rows+1):
        for j in range(i):
          print("*", end=" ")
        print()

    
def main():
    rows = int(input("Enter the number of rows => "))
    printPattern(rows)
        
main()

