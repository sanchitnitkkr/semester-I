# Draw a pie chart representing the percentage of expenses of different items (eg food,rent,transport, entertainment)

import matplotlib.pyplot as plt

items = ["food", "rent", "transport", "entertainment"]
expenses = [9000, 11000, 3000, 2500]

plt.pie(expenses,labels=items,autopct="%1.1f%%")
plt.title("Expenses breakup pie chart")
plt.show()