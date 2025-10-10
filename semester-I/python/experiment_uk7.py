def getUniqueElements(list1):
    return list(set(list1))

def main():
    list1 = list(map(int,input("Enter the list of numbers comma separated: ").strip().split(",")))
    print(getUniqueElements(list1))

main()