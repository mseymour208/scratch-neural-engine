from sklearn.metrics import log_loss
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, classification_report
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler
import pandas as pd

df = pd.read_csv(r'C:\Users\Mikle\OneDrive\Desktop\scratch-neural-engine\DATA\spambase.csv')
X = df.iloc[:, :57]
y = df.iloc[:, 57]

scaler = MinMaxScaler()
x_scaled = scaler.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(x_scaled, y, test_size=0.2, random_state=42)

mlp = MLPClassifier(
    hidden_layer_sizes=(16,),
    activation="logistic",
    solver="sgd",
    learning_rate_init=0.1,
    learning_rate="constant",
    momentum=0.0,
    alpha=0.0,
    batch_size=1,
    max_iter=1000,
    tol=0.0,
    n_iter_no_change=1000,
    random_state=42,
    verbose=True,
)

mlp.fit(X_train, y_train)

probabilities = mlp.predict_proba(X_test)[:, 1]
predictions = (probabilities >= 0.5).astype(int)

print(f'Accuracy: {accuracy_score(y_test, predictions) * 100:.4f}%')
print(f'Final Train Loss: {mlp.loss_:.6f}')
print(f'Test BCE Loss: {log_loss(y_test, probabilities):.6f}')
