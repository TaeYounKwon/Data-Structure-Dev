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
tmp = {'a':1,'b':2,'c':3}
myList.extend(tmp.values())
print(myList)

def submit():
    print('hello')
    return 'world'

print(submit())