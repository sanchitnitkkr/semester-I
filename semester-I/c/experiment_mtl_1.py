# Plot a simple line chart showing the relationship b/w days of the week and and number of study hours using matplotlib.pyplot.plot()

import matplotlib.pyplot as plt

days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
study_hours = [2, 3, 4, 3, 5, 1, 0]

plt.plot(days, study_hours)
plt.xlabel("Day of the Week")
plt.ylabel("Study Hours")
plt.title("Study Hours Across the Week")
plt.tight_layout()
plt.show()
