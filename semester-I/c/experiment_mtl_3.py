# Draw a scatter plot comparing marks in Maths vs Science for 10 students

import matplotlib.pyplot as plt
import numpy as np

# Example data
students = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J"]
math_marks = [12, 10.5, 11, 11.5, 6.5, 8, 7.5, 8, 9, 10]
science_marks = [13, 10, 11, 12, 10, 13, 13, 10, 11, 15]

x = np.arange(len(students))
width = 0.35  # bar width

# plt.figure()
plt.bar(x - (width / 2), math_marks, width)
plt.bar(x + (width / 2), science_marks, width)

plt.xticks(x, students)
plt.xlabel("Days of the Week")
plt.ylabel("Marks")
plt.title("Marks across maths and science")
plt.tight_layout()
plt.show()
