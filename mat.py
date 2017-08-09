import matplotlib.pyplot as plt
import numpy as np
path = '../pgData/'
file = 'rawdata0@1m&5000m.bin'

data=np.fromfile(path+file,dtype=np.double)
data.shape = 12000,5200
A = data.T
E = A[2000:4000,0:12000]

C = np.zeros([2000,12000],dtype=np.double)
for i in range(0,2000):
    print i
    for j in range(0,11999):
        C[i,j]=E[i,j+1]-E[i,j]
C = np.abs(C)

figure=plt.figure(facecolor='w')  
ax=figure.add_subplot(1,1,1,position=[0.1,0.15,0.8,0.8])
ax.imshow(E,interpolation='nearest', cmap='bone', origin='lower',aspect='auto')
plt.colorbar(shrink=.92)
plt.show()
