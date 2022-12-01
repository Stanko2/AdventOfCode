res = 0

while True:
    a = input()
    if a == 'exit':
        break
    b = a.split('|')[0].split(' ')
    currMap = {}
    b = list(map(lambda x: sorted(x), b))
    for i in b:
        if len(i) == 2:
            currMap[1] = set(i)
        elif len(i) == 3:
            currMap[7] = set(i)
        elif len(i) == 4:
            currMap[4] = set(i)
        elif len(i) == 7:
            currMap[8] = set(i)
    for i in b:
        if len(i) == 6:
            if len(currMap[1].intersection(set(i))) < 2:
                currMap[6] = set(i)
            elif len(currMap[4].intersection(set(i))) < 4:
                currMap[0] = set(i)
            else:
                currMap[9] = set(i)
        elif len(i) == 5:
            if len(currMap[1].intersection(set(i))) == 2:
                currMap[3] = set(i)
            elif len(currMap[4].intersection(set(i))) == 3:
                currMap[5] = set(i)
            elif len(currMap[4].intersection(set(i))) == 2:
                currMap[2] = set(i)
    c = a.split('|')[1].split(' ')
    num = 0
    for i in c:
        for j in currMap.keys():
            if ''.join(sorted(''.join(currMap[j]))) == ''.join(sorted(i)):
                num += j
                break
        num *= 10
    res += num
print(res)
