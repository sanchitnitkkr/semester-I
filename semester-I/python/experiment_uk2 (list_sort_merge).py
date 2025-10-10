def merge(list1,list2):
    fp = 0
    sp = 0
    m = len(list1)
    n = len(list2)
    result = []
    
    while(fp<m or sp<n):
        if(fp==m and sp!=n):
            result.append(list2[sp])
            sp+=1
        elif(fp!=m and sp==n):
            result.append(list1[fp])
            fp+=1
        elif(list1[fp] >= list2[sp]):
            result.append(list2[sp])
            sp+=1
        else:
            result.append(list1[fp])
            fp+=1
    return result

def main():
    list1 = list(map(int,input("Please enter comma separated values for the first list => ").strip().split(',')))
    list2 = list(map(int,input("Please enter comma separated values for the second list => ").strip().split(',')))
    
    # Using the inbuilt sorting function as of now
    list1.sort()
    list2.sort()
    
    # Merge both the sorted lists
    sortedMergedList = merge(list1,list2)
    print(sortedMergedList)
    
    
main()