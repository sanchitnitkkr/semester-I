# Create a histogram with customized
# bins and colors to show
# age group distribution.

import matplotlib.pyplot as plt

ages = [18, 19, 20, 24, 23, 25, 17, 21, 22]

plt.figure(figsize=(7, 4))

# Histogram with custom bins and color
plt.hist(ages, bins=[15, 18, 21, 24, 27], color="skyblue", edgecolor="black")

plt.xlabel("Age Groups")
plt.ylabel("Frequency")
plt.title("Age Group Distribution")
plt.show()
