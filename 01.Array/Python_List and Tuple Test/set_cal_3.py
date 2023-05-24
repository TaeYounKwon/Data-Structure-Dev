mySet = {1,2,3,4,5}
tmpSet = {4,5,6}

# '|=' 연산자 사용
mySet |= tmpSet
print(mySet) # {1, 2, 3, 4, 5, 6}

# union() 함수 사용
result= mySet.union([6,7])
print(result) # {1, 2, 3, 4, 5, 6, 7}
print(mySet) # {1, 2, 3, 4, 5, 6}

# update() 함수 사용
result = mySet.update((7,8))
print(result) # None
print(mySet) # {1, 2, 3, 4, 5, 6, 7, 8}