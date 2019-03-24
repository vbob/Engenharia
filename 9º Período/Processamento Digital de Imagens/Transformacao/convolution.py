import scipy.signal as signal

x = [0,0,0,1,0,0,0,0]
y = [1,2,3,2,8]

z = signal.convolve(x,y)
print(z)