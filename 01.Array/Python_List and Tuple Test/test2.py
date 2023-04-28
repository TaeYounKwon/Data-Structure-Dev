myList = [1,2,3,4,5]
tmpList = [6,7,8]
# x = myList.insert(-1,7)
# print(myList)

myList.append(tmpList)
print(myList)

myList = [1,2,3,4,5]
tmpList = [6]
myList.extend(tmpList)
print(myList)