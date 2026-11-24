import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

# Load the dataset
data = pd.read_csv('cpa_plot.csv')
print(data.head())

# Scale the data
scaler = StandardScaler()
scaled_data = scaler.fit_transform(data)

# Perform PCA
pca = PCA(n_components=2)
pca_result = pca.fit_transform(scaled_data)

print("PCA Components:\n", pca.components)
print("Explained Variance Ratio:", pca.explained_variance_ratio_)

# Plot the PCA results
plt.scatter(pca_result[:, 0], pca_result[:, 1], c='blue', s=100)
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')
plt.title('PCA Discrimination Result')
plt.grid(True)
plt.show()
