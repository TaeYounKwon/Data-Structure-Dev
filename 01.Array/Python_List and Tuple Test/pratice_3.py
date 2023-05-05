myList = [1,2,3,4,5]
myTuple = (1,2,3,4,5)
tmpList = [6,7,8]
tmpTuple = (6,7,8)

tmpList.extend(myList)
myList = tmpList
print(myList)
myList.clear()
