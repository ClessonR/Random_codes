#%%
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import statsmodels.api as sm
import seaborn as sns
sns.set()

data = pd.read_csv('real_estate_price_size_year.csv')
data.describe()



y = data['price']
x1 = data[['size','year']]

x = sm.add_constant(x1) #! Creating the regression
results = sm.OLS(y,x).fit()
results.summary() #? Getting the results

