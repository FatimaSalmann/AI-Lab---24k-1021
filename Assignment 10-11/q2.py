import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import mean_absolute_error, mean_squared_error
from sklearn.linear_model import LinearRegression
from sklearn.tree import DecisionTreeRegressor
import numpy as np

df = pd.read_csv("train.csv")

df = df.dropna(axis=1)

X = df.drop("SalePrice", axis=1)
y = df["SalePrice"]

X = pd.get_dummies(X)

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(
    X_scaled, y, test_size=0.3, random_state=42
)

lr = LinearRegression()
lr.fit(X_train, y_train)
y_pred_lr = lr.predict(X_test)

dt = DecisionTreeRegressor(max_depth=10)
dt.fit(X_train, y_train)
y_pred_dt = dt.predict(X_test)

def evaluate(y_true, y_pred):
    print("MAE:", mean_absolute_error(y_true, y_pred))
    print("RMSE:", np.sqrt(mean_squared_error(y_true, y_pred)))

print("Linear Regression:")
evaluate(y_test, y_pred_lr)

print("\nDecision Tree:")
evaluate(y_test, y_pred_dt)
