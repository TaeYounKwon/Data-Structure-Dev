myList = [1,2,3,4,5]
myTuple = (1,2,3,4,5)
tmpList = [6,7,8]
tmpTuple = (6,7,8)
mydict = {1:'a',2:'b',3:'c'}
tmpdict = {4:'d',5:'e'}

myList.extend(tmpList)
# print(myList)

myList = [1,2,3,4,5]
myList.extend('abcde')
# print(myList)

# a = (1,2,3) + 456