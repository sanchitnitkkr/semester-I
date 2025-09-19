# Write a program to search the element of the list if element is found then break the loop and print index

def findElement(array,element):
    for i in range(0,len(array)):
        if(array[i] == element):
            print("Found at index =>",i)
            break

def main():
    eleList = input("Enter elements separated by commas => ").strip().split(",")       
    eleFind = (input("Enter element to be found=> ").strip())
    findElement(eleList,eleFind)

main()    