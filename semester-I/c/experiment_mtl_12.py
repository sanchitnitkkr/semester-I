# 7. Combine Pandas and Matplotlib to
# plot a bar chart of total sales
# per region from a dataset.

import pandas as pd
import random as rnd
import matplotlib.pyplot as plt

regions = [
    "North America",
    "South America",
    "Europe",
    "Asia",
    "Africa",
    "Australia",
    "Antarctica",
    "Middle East",
    "Central America",
    "Caribbean",
    "Scandinavia",
    "Eastern Europe",
    "Western Europe",
    "Southeast Asia",
    "Central Asia",
]

regions = rnd.choices(regions,k=10)
sales = [rnd.randint(1, 100) for _ in range(10)]

df = pd.DataFrame({
    "Regions": regions,
    "Sales": sales
})

plt.figure(figsize=[11,5])
plt.bar(regions,sales)
plt.show()