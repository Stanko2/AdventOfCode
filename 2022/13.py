from functools import cmp_to_key
input = []

with open('2022/in13') as f:
    input = f.readlines()

def Compare(a,b):
    if isinstance(a, int) and isinstance(b, int):
        if a == b:
            return 0
        return 1 if a < b else -1
    elif isinstance(a, int):
        return Compare([a], b)
    elif isinstance(b, int):
        return Compare(a, [b])
    for i in range(min(len(a), len(b))):
        x = Compare(a[i], b[i])
        if x == 0:
            continue
        return x
    if len(a) == len(b):
        return 0
    return 1 if len(a) < len(b) else -1

dobre = 0
packets = []
for i in range(len(input)):
    packets.append(eval(input[i]))

for i in range(0, len(input), 2):
    if Compare(packets[i], packets[i+1]) == 1:
        dobre += i // 2 + 1
packets.append([[2]])
packets.append([[6]])
packets.sort(key=cmp_to_key(Compare), reverse=True)
print(dobre)
print((packets.index([[2]])+1) * (packets.index([[6]])+1))