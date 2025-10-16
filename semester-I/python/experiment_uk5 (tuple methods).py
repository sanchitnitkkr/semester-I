# Tuple methods demonstration

## Tuples are indexed, immutable and allow duplicates
tuple1 = (1,2,3,4,5,)


## Accessing Tuples
### Tuples can be executed similarly as lists
print(tuple1[1]) # Prints second element
print(tuple1[-1]) # Prints last element

### Accessing using range, Syntax: [start:stop] [Upper limit exclusive]
### By default start is 0 and end is size
### Start and stop can be negative as well like [-3:-1]
print(tuple1[0:2])

### Slicing tuples 
### Method 1
tuple2 = tuple1[0:2]
print(tuple2 is tuple1)
print(tuple2)
### Method2 
sliceObject = slice(0,2)
tuple2 = tuple1[sliceObject]
print(tuple2)

### Concatenation
tuple1 = (1,2,3)
tuple2 = (3,4,5)
tuple3 = tuple1 + tuple2

#### Tuples can also be duplicated using the * symbol
#### For example :
tuple4 = tuple1 * 2 # (1,2,3,1,2,3)




