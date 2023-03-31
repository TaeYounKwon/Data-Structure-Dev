Sample1 = (1, 'abc', True, [2,3,4], '5')
# print(type(Sample1)) # <class 'tuple'>

Sample2 = [1, 'abc', True, [2,3,4], '5']
# print(type(Sample2)) # <class 'list'>

Sample3 = (1, 'abc', True, (2,3,4), '5')
#print(type(Sample3)) # <class 'tuple'>

Sample4 = [1, 'abc', True, (2,3,4), '5']
#print(type(Sample4)) # <class 'list'>

# print("------------------")
# for value in Sample4:
#     print(type(value))
    
newTuple = (2 , 3, 4, 5, 6)
newTuple = (1, ) + newTuple
print(newTuple)
    