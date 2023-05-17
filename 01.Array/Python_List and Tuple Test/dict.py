# myDict = {'모코코':['lv1','green'],'머코코':['lv2','yellow'],'무코코':['lv3','rainbow ']}
# a = myDict.keys() #
# a_list = list(myDict.keys())
# b = myDict.values()
# b_list = list(myDict.values())
# c = myDict.items()
# c_list = list(myDict.items())
# # d = myDict.pop('ma')

# print(a)
# print(a_list)
# print(b)
# print(b_list)
# print(c)
# print(c_list)
# print(d)
# tmp = {1:'1',2:'2'}
# tmp2 = {3:'3',4:'4'}
# tmp3 = {5:'5',6:'6'}
# mydict = dict(모코코 = tmp, 머코코=tmp2, 무코코=tmp3)
# print(mydict)

# mydict = {{1:'1',2:'2'}:'abc','A':13}
# print(mydict)
myDict = {1:'A','BCD':2, ('E','F'):3}

# a = myDict.keys()
# print(a) 
# tmp = (1,2,3)
# myDict = dict('1' = '1',bc='2',cd='3')
# a = myDict.keys()
# print(a)
# a_list = list(a)
# print(a_list)

# myDict = {1:'LEFT',2:'MIDDLE',3:'LEFT'}
# print(myDict)

# key()를 사용하여 딕셔너리의 키 값 얻기
# a = myDict.values()
# a_list = list(a) 
# print(a) # dict_keys([1, 'BCD', ('E', 'F')])
# print(a_list) # [1, 'BCD', ('E', 'F')]
myDict = {1:'A','BCD':2, ('E','F'):3}
# a = myDict.items()
# print(a)
# for key, val in myDict.items():
# 	print('key = ',key, ' value = ',val)
    
# a = myDict.popitem()
# print(a)
# print(myDict)
# del myDict[1]
# print(myDict)

print(1 in myDict)
print(2 in myDict)

print('BCD' not in myDict)
print(('G','H') not in myDict) 
