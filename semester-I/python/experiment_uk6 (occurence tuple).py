def printOccurences(tuple1):
    myDict = {}
    for element in tuple1:
        if element not in myDict.keys():
            myDict[element] = 0
        
        myDict[element] +=1
    
    print(f"The tuple occurences are:")
    print(myDict)
    
def main():
    tuple1= tuple(map(int,input("Please enter comma separated values for the tuple => ").strip().split(',')))
    printOccurences(tuple1)
    
main()