myList = [3,'3',[3],(3,),33]
myList2 = [3,'3',[ ],(3,),33]

tmpList = ['',[ ],(), False, 0]
tmpList2 = ['',[ ],(), False, 1]

print(all(myList))
print(all(myList2))
print(all(tmpList))
print(all(tmpList2))
print('-------')
print(any(myList))
print(any(myList2))
print(any(tmpList))
print(any(tmpList2))
