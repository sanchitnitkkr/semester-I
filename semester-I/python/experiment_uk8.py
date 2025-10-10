def main():
    duplicates = set()
    updatedList = []

    list1 = list(map(int,input("Enter the list of numbers comma separated: ").strip().split(",")))
    for ele in list1:
        if ele not in duplicates:
            updatedList.append(ele)
            duplicates.add(ele)
        
    print(updatedList)

main()