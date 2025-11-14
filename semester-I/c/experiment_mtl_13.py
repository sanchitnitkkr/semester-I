# 8. Use Seaborn’s countplot() to 
# display the frequency of categorical 
# variables like gender or department.

import seaborn as sns
import matplotlib.pyplot as plt

gender = ["Male", "Female", "Female", "Male", "Female", "Female", "Male"]

sns.countplot(x=gender)
plt.title("Gender Distribution")
plt.xlabel("Gender")
plt.ylabel("Count")
plt.show()
