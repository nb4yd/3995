import pandas as pd
df=pd.read_csv('longBfield.dat' )
df.drop(['Btot'], axis = 1, inplace=True)
df.to_csv('longBfield.dat', header=True, index=None)
