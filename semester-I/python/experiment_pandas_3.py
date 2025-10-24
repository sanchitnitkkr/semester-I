import pandas as pd

sales = {
    "Product": ["Pen","Book","Pencil","Eraser"],
    "Price": [10,50,5,8],
    "Quantity": [20,10,50,30],
}

df = pd.DataFrame(sales)

# Add a new column Total = Price * Quantity
df["Total"] = df["Price"] * df["Quantity"]

# Increase all prices by 10%
df["Price"] = df["Price"] +  (df["Price"] * 0.1)

# Delete the quantity column
df.drop("Quantity",axis=1)