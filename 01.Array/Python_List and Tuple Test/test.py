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
# print(newTuple)
myList = list((True,'Two', (3,4), 6, [6,7]))
# print(myList)
myDict = { 1:'kiwi',2:'Melon',3:'Apple'}
myList = list(myDict.keys())
myList = list(myDict.values())
print(myList)
