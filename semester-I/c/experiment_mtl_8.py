# Plot multiple lines on the same graph to
# compare sales trends of two companies
# across months

import matplotlib.pyplot as plt

# Data
months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]

company_A = [120, 135, 150, 160, 180, 200, 190, 210, 220, 230, 240, 250]
company_B = [100, 115, 130, 140, 160, 170, 165, 180, 190, 200, 210, 220]

plt.figure(figsize=(10, 5))

# Plot both lines
plt.plot(months, company_A, marker='o', label="Company A")
plt.plot(months, company_B, marker='s', label="Company B")

# Labels and title
plt.xlabel("Months")
plt.ylabel("Sales")
plt.title("Sales Trends Across Months")

# Show legend
plt.legend()

plt.tight_layout()
plt.show()
