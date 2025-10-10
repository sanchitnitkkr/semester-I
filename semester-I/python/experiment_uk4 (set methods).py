def main():
    set1 = set(map(int,input("Please enter comma separated values for the first set => ").strip().split(','))) # 1,2,3,4
    set2 = set(map(int,input("Please enter comma separated values for the second set => ").strip().split(','))) # 4,5,6,7
    
    # Union of two sets (Same as Maths union of two sets)
    ## Method 1 
    set3 = set1.union(set2) 
    print(set3) # {1,2,3,4,5,6,7}
    ## Method 2
    set3 = set1 | set2 # {1,2,3,4,5,6,7}
    
    # Intersection (Returns the common elements)
    ## Method 1
    set3 = set1.intersection(set2) 
    print(set3) # {4}
    ## Method 2
    set3 = set1 & set2 
    print(set3)
    
    # Difference of two sets (Removes the elements of the second set from the first set)
    ## Method 1
    set3 = set1.difference(set2)
    ## Method 2
    set3 = set1 - set2
    print(set3) # {1,2,3}
    
    # Symmetric Difference of two sets (Returns elements which are not common in both sets)
    ## Method 1
    set3 = set1.symmetric_difference(set2) # {1,2,3,5,6,7}
    print(set3)
    ## Method 2
    set3 = set1 ^ set2
    
    
    
    
    
    
    
main()