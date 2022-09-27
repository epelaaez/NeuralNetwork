import numpy as np
from matplotlib import pyplot as plt

with open("data/train.csv") as file:
    file = list(file)
    data = [int(i.replace("\n", "")) for i in file[89].split(",")] # index i of file[i] chooses the image to display

data = np.array(data)
data = np.resize(data, (32, 32))
data = data.T
plt.imshow(data, cmap='gray', vmin=0, vmax=255)
plt.show()