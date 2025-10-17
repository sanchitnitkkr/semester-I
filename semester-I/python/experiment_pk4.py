# WAP that reads data from one file and writes all uppercase words to another file

sourceFile = open("C://Users/hp/Desktop/semester-I/semester-I/python/experiment_pk4_input", "r")
destinationFile = open("C://Users/hp/Desktop/semester-I/semester-I/python/experiment_pk4_output", "w")

for line in sourceFile:
    destinationFile.write(line.upper())
    
sourceFile.close()
destinationFile.close()