import pandas as pd


data = {
    "Employee": ["A", "B", "C", "D", "E", "F"],
    "Department": ["HR", "IT", "IT", "Finance", "Finance", "HR"],
    "Salary": [30000, 50000, 55000, 45000, 40000, 32000],
    "Experience": [2, 5, 3, 4, 2, 6],
}

df = pd.DataFrame(data)


# 1. Display the highest salary in each department.
print(df.groupby('Department')["Salary"].max())


# 2. Find the average experience by department.
print(df.groupby("Department")[["Experience"]].mean())

# 3. Add a new column Bonus = 0.1 * Salary only for employees with Experience > 3.
df.loc[df["Experience"] > 3, "Bonus"] = 0.1 * df["Salary"]

# 4. Show the department with the maximum total salary.
result = df.groupby("Department")["Salary"].sum()
print("Department with max total salary:", result.idxmax())