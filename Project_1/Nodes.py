
# Nodes Expanded VS Solution Depth

import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]

y1 = [2, 3, 4, 5, 6, 7, 8, 9, 11, 14, 18, 21, 27, 28]

y2 = [2, 3, 4, 5, 6, 7, 8, 19, 29, 40, 67, 112, 159, 213]

y3= [2, 4, 19, 23, 47, 65, 124, 287, 449, 497, 1160, 1937, 2422, 4184]

plt.plot(x, y1, label = 'A* Manhattan Distance')

plt.plot(x, y2, label="A* Misplaced Tile")

plt.plot(x, y3, label="Uniform Cost Search")

plt.xlabel('Depth')

plt.ylabel('Nodes Expanded')

plt.title('Nodes Expanded vs Solution Depth')

plt.legend()

plt.savefig("Nodes Expanded vs Solution Depth")

plt.show()
