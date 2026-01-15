# Draw a boxplot to visualize 
# the distribution of student marks 
# and detect outliers.

import seaborn as sns
import matplotlib.pyplot as plt

# Example student marks
marks = [45, 50, 55, 60, 62, 65, 68, 70, 72, 75, 80, 85, 88, 90, 95, 100, 30, 110]

plt.figure(figsize=(6, 4))
sns.boxplot(data=marks)
plt.title("Boxplot of Student Marks")
plt.ylabel("Marks")
plt.show()
