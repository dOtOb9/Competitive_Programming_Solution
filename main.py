from matplotlib import pyplot as plt


a, b = input()
def f(x):
    return a * x / b - a * (x / b)

x = [i for i in range(0, 100)]
y = [f(i) for i in x]

plt.plot(x, y)