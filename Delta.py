import pandas as pd
import numpy as np
import sys
from math import sqrt

df = pd.read_csv("Delta_test_data.txt", header=[0], sep='\s', engine='python')

px = df['Px'].tolist()
py = df['Py'].tolist()
pz = df['Pz'].tolist()

originial_stdout = sys.stdout

with open('Delta.csv', 'w') as f:
    sys.stdout = f
    for i in range(df.shape[0]):
        px[i] = float(px[i])
        py[i] = float(py[i])
        pz[i] = float(pz[i])
        print(px[i], py[i], pz[i])

#sys.stdout=original_stdout
