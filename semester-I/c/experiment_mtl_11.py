# 6. Visualize a 3D surface or scatter plot using
# matplotlib.pyplot.axes(projection='3d')

import matplotlib.pyplot as plt
import numpy as np

# Random 3D data
x = np.random.randint(0, 50, 100)
y = np.random.randint(0, 50, 100)
z = np.random.randint(0, 50, 100)

ax = plt.axes(projection='3d')

ax.scatter(x, y, z)

ax.set_title("3D Scatter Plot")
ax.set_xlabel("X-axis")
ax.set_ylabel("Y-axis")
ax.set_zlabel("Z-axis")

plt.show()

