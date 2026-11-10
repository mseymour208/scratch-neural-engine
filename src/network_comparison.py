from sklearn.metrics import log_loss
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
import pandas as pd

df = pd.read_csv('breast+cancer+wisconsin+diagnostic/wdbc.data')

