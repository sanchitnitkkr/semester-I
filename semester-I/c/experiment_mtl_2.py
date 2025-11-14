# Create a bar chart showing the number of students enrolled in different courses (eg MCA, BTech, BBA and MBA)
import matplotlib.pyplot as plt

courses = ["MCA", "MBA", "BTech", "BBA", "BCA", "Msc", "MTech", "BBA"]
studentCount = [12, 5, 15, 5, 4, 4, 8, 5]

plt.bar(courses, studentCount)
plt.xlabel("Courses")
plt.ylabel("Student count")
plt.title("No of students per course")
plt.show()
