# 9. Create an advanced visualization 
# — for example, overlay a line plot on a bar plot
# using dual y-axes (twinx()).

import matplotlib.pyplot as plt

# Data
months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun"]
sales = [120, 150, 180, 220, 260, 300]        
profit_percent = [10, 12, 8, 15, 18, 20]

fig, ax1 = plt.subplots()

ax1.bar(months, sales)
ax1.set_xlabel("Months")
ax1.set_ylabel("Sales", color="black")

ax2 = ax1.twinx()  
ax2.plot(months, profit_percent, marker="o")
ax2.set_ylabel("Profit %", color="black")

plt.title("Sales vs Profit Percentage")
plt.show()
