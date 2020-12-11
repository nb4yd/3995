import pandas as pd
import numpy as np
import sys
from math import sqrt

df = pd.read_csv("ntuples.txt", header=[1], sep='\s', engine='python')

#for i in range(1,df.shape[0]):
    #px1[i] = df.at[i,'Px']
    #py1[i] = df.at[i,'Py']
    #pz1[i] = df.at[i,'Pz']
    #print(px1[i])
    #print(py1[i])
    #print(pz1[i])

px1 = df['Detectori_Px'].tolist() # list of initial Px values
 
py1 = df['Detectori_Py'].tolist() # " "
pz1 = df['Detectori_Pz'].tolist() # " "

px2 = df['Det_Px'].tolist() # list of final Px values
py2 = df['Det_Py'].tolist() # " "
pz2 = df['Det_Pz'].tolist() # " "

pid = df['Det_PDGid'].tolist() # list of particle IDs

original_stdout = sys.stdout

with open('data.dat', 'w') as f:
    sys.stdout = f
    print('First Detector:\n')
    for i in range(df.shape[0]):
        px1[i] = float(px1[i])
        py1[i] = float(py1[i])
        pz1[i] = float(pz1[i])
        F = pow(px1[i],2) + pow(py1[i],2) + pow(pz1[i],2)
        E = sqrt(pow(0.511,2) + F)
        print(pid[i], px1[i], py1[i], pz1[i], E)
        

    print('\n\n\nSecond Detector - after scattering:\n')

    for j in range(df.shape[0]):
        px2[j] = float(px2[j])
        py2[j] = float(py2[j])
        pz2[j] = float(pz2[j])
        F = pow(px2[j],2) + pow(py2[j],2) + pow(pz2[j],2)
        E = sqrt(pow(0.511,2) + F)
        print(pid[j], px2[j], py2[j], pz2[j], E)
    sys.stdout = original_stdout
    
 

