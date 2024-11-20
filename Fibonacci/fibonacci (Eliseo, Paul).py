import numpy as np

def fibonacci_matriz(n):
    F = np.array([[1, 1], [1, 0]], dtype=object)
    result = np.linalg.matrix_power(F, n)
    return result[0, 1]

# Ejemplo de uso
n = 10
print(f"Fibonacci de {n}: {fibonacci_matriz(n)}")