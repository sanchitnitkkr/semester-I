# Create a heatmap using Seaborn to 
# show the correlation 
# between columns in a Dataframe

import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd

# Example DataFrame
data = {
    "Math": [90, 85, 78, 92, 88],
    "Science": [85, 80, 70, 95, 90],
    "English": [75, 88, 82, 80, 85],
    "History": [70, 78, 85, 80, 90]
}

df = pd.DataFrame(data)

# Compute correlation matrix
corr = df.corr()

# Plot heatmap
plt.figure(figsize=(8, 6))
sns.heatmap(corr, annot=True, cmap="coolwarm", linewidths=0.5)
plt.title("Correlation Heatmap")
plt.show()





