
# Maximum Queue size VS Solution Depth

import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]

y1 = [3, 3, 4, 4, 5, 7, 8, 10, 11, 13, 16, 19, 23, 23]

y2 = [3, 3, 4, 4, 5, 7, 8, 16, 24, 30, 48, 83, 113, 158]

y3= [3, 4, 14, 20, 36, 45, 89, 190, 291, 337, 706, 1210, 1634, 2502]

plt.plot(x, y1, label = 'A* Manhattan Distance')

plt.plot(x, y2, label="A* Misplaced Tile")

plt.plot(x, y3, label="Uniform Cost Search")

plt.xlabel('Depth')

plt.ylabel('Max Queue Size')

plt.title('Max Queue Size vs Solution Depth')

plt.legend()

plt.savefig("Max Queue Size vs Solution Depth.png")

plt.show()

