import pandas as pd

data = {
    "Dept": ["CSE", "CSE", "IT", "IT", "ECE", "ECE"],
    "Student": ["A", "B", "C", "D", "E", "F"],
    "Marks": [85, 90, 78, 92, 88, 80],
}

df = pd.DataFrame(data)

#1. Display students having marks greater than 85.
print(df[df["Marks"] > 85])

# 2. Find the average marks per department using groupby() and mean().
print(df.groupby("Dept")["Marks"].mean())
