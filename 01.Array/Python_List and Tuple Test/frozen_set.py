# 프로즌 세트 생성
f_set = frozenset(range(5))

print(f_set) # frozenset({0,1,2,3,4})

# 프로즌 세트로 세트 안에 세트값 넣기
mySet = {f_set,5,6}
print(mySet)

myDict = {f_set:'abcdef'}
print(myDict)