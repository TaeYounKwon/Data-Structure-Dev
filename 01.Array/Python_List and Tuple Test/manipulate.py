myList = [1,2,3,4,5]

x= myList.remove(3) #remove 안에 원소가 없을 경우 ValueError
print(myList)
print(x)

# myList = [1,2,3,4,5]
# y = myList.pop(5) # pop(안에 index 값을 넣어주면 index 값 삭제, 삭제된 값을 리턴), 안넣어주면 가장 마지막 원소 삭제
# print(myList)
# print(y)

myList = [1,2,3,4,5]
del myList
print(myList)

# del myList # 인덱스를 안줄 경우 myList 모두 삭제
# print(myList) # NameError 리스트가 삭제되었기에 myList가 존재하지 않음

# tmpList = []
# tmpList.pop()