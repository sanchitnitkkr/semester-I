# Display multi plots (line and bar) in a single figure using subplot()
import matplotlib.pyplot as plt

days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
count = [4,3,2,4,2,1,1]

plt.figure(figsize=(13, 5))

plt.subplot(1, 2, 1)       # (rows, columns, plot number)
plt.plot(days, count)
plt.title("Study Hours (Line Plot)")
plt.xlabel("Days")
plt.ylabel("Hours")

plt.subplot(1, 2, 2)
plt.bar(days, count)
plt.title("Sleep Hours (Bar Chart)")
plt.xlabel("Days")
plt.ylabel("Hours")


plt.show()
