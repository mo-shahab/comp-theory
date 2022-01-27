import numpy as np

a = np.array([1, 3, 5, 6, 5, 7])                                #print(a) - this prints the type of the a     
b = np.array((2, 4, 6, 7, 8, 9), dtype = 'f')                   #defo of the numpy array 

'''
print(b) - this prints the type of the b, it should output of
nd.array
print(type(a))
print(type(b))

print(a.dtype) - this prints what datatype does the "a" array
holds. 
this will output int 32 since the \n
elements in the "a" array are of int type
print(b.dtype) - we know this obvi, the o/p is float 32 since 
we defined the datatype
'''

#DIMENSIONS

_a = np.array([[1, 2, 3], [4, 5, 6]])                           #the 2d thingy
print(_a.ndim)                                                  #o/p is 2

_b = np.array([[[1, 2, 3], [4, 5, 6]], [[1, 2, 3], [4, 5, 6]]])
print(_b.ndim)

print(_b[1, 0, 2])

'''
what does it mean by shape:
shape returns a tuple

'''