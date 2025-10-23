import pandas as pd

data = {
    "City": ["Delhi","Delhi","Mumbai","Mumbai","Chennai","Chennai"],
    "Month": ["Jan","Feb","Jan","Feb","Jan","Feb"],
    "Marks": [20000,22000,18000,21000,15000,17000],
}

df = pd.DataFrame(data)

#1. Group data by City and compute 
#  total and average sales using .agg(['sum''mean']).
result = df.groupby("City")["Marks"].agg(['sum', 'mean'])
print(result)

# 2. Sort the result by average sales in descending order.
result = result.sort_values("mean", ascending=False)
print(result)