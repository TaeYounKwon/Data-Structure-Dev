myList = [5,-3,4,-1,2]
myTuple = (5,-3,4,-1,2)

# a = myList.reverse( key = lambda x : abs(x))
# print(myList)
# print(a)
# myList = [5,-3,4,-1,2]


# a = reversed(myList)

# b = list(a)
# c = tuple(reversed(myList)) # <- 좀더 공부해야할 필요가 있음 

# d = str(a) # '<list_reverseiterator object at 0x000001C7D2940FD0>' 
# d = list(d) # 
# # e = int(a)
# print(myList)
# print('a',a)
# print('b',b)
# print('c',c) # 반환자 타입 바로 튜플타입은 불가능 / 먼저 리스트 타입으로 바꿔준 다음에 튜플타입으로 
# print('d',d)
# print(e)

# a = reversed(myTuple)
# print('a',a)
# b = list(a)
# print('b',b)
# c = tuple(reversed(myTuple))
# print('c',c)

reversed(myTuple, key= lambda x : abs(x))