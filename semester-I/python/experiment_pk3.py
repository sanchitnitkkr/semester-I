# WAP to read a txt file and count the no of lines, words and characters in it

myFile = open("C://Users/hp/Desktop/semester-I/semester-I/python/experiment_pk3")

numOfLines = 0
numOfWords = 0
numOfChars = 0

for line in myFile:
    numOfLines+=1
    if(line == "\n"):
        numOfChars += 2
        continue
    
    words = line.split(" ")
    for word in words:
        numOfChars+= len(word)
    
    numOfWords += len(words)
    
print("Lines => ",numOfLines)
print("Words => ",numOfWords)
print("Characters => ",numOfChars)

myFile.close()