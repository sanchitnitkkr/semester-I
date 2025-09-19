# Write a program to ask a suer to enter a number until zero is entered

def main():
    while True:
        inputNum = int(input("Please enter zero=> ").strip())
        if(inputNum !=0):
            continue 
        break
    print(inputNum)
    
main()