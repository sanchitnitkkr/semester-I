def isSubset(a,b):
    for i in a:
         if i not in b:
             return False
                             
    return True
    
def main():
    setA =  set(map(int, input("Enter comma separated values for the first set => ").strip().split(",")))
    setB = set(map(int, input("Enter comma separated values for the second set => ").strip().split(",")))
    aIsSubsetOfB = isSubset(setA,setB)
    print(f"Set A is indeed a subset of B" if aIsSubsetOfB else f"Set A is not a subset of B")
    
main()