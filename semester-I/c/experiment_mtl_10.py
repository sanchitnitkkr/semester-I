# 5. Use Seaborn’s pairplot() to visualize 
# pairwise relationships in a dataset 
# (e.g., Iris dataset).

import seaborn as sns
import matplotlib.pyplot as plt

# Load Iris dataset
iris = sns.load_dataset("iris")

# Create pairplot
sns.pairplot(iris, hue="species", diag_kind="kde")

plt.show()
