import pandas as pd

data = [["Sanchit", "COA", 95], ["Ola", "Discrete Maths", 75], ["Saksham", "Maths", 50],['Madhav',"English",89]]

df = pd.DataFrame(data, columns=["Name", "Subject", "Marks"])

# Print first two rows
print(df.head(2))

# Print column names, data types and shape
print(df.columns.to_list()) # Name, Subject and Marks are columns
print(df.dtypes) # Object for strings and int64 for marks
print(df.shape) # 4 rows 3 columns

# Compute Average Marks
print(df["Marks"].mean())
