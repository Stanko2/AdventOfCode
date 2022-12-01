a = []


def parse_num(num: str):
    a = []
    for i in num:
        if i == '[':
            a.append(i)
        elif i == ']':
            a.append(i)
        elif i == ',':
            continue
        else:
            a.append(int(i))
    return a


def explode(a):
    d = 0
    for i in range(len(a)):
        if a[i] == '[':
            d += 1
        elif a[i] == ']':
            d -= 1
        elif isinstance(a[i], int):
            if d == 5:
                first = a[i]
                second = a[i+1]
                b = a[:i-1]
                j = i-2
                while not isinstance(b[j], int):
                    j -= 1
                    if j < 0:
                        break
                if j > 0:
                    b[j] += first
                b.append(0)
                b.extend(a[i+3:])
                j = i
                while not isinstance(b[j], int):
                    j += 1
                    if j >= len(b):
                        break
                if j < len(b):
                    b[j] += second
                return True, b
    return False, a


def split(a):
    for i in range(len(a)):
        b = a[i]
        if isinstance(b, int):
            if b >= 10:
                c = a[:i]
                c.extend(['[', b//2, (b+1)//2, ']'])
                c.extend(a[i+1:])
                return True, c
    return False, a


def reduce(a):
    reduced = True
    while reduced:
        reduced, a = explode(a)
        if not reduced:
            reduced, a = split(a)
    return a


def get_magnitude(a):
    i = 0
    while len(a) > 1:
        if isinstance(a[i], int) and isinstance(a[i+1], int):
            mag = 3 * a[i] + 2 * a[i+1]
            del a[i-1:i+3]
            a.insert(i-1, mag)
            i -= 2
        else:
            i += 1
    return a[0]


def add(a, b):
    c = ['[']
    c.extend(a)
    c.extend(b)
    c.extend(']')
    return c


a = input()
a = parse_num(a)
numbers = [a]
while True:
    b = input()
    if b == "exit":
        break
    b = parse_num(b)
    numbers.append(b)
mag = 0
for i in range(len(numbers)):
    for j in range(len(numbers)):
        if i == j:
            continue
        x = reduce(add(numbers[i], numbers[j]))
        mag = max(mag, get_magnitude(x))
# print(a)
# print(get_magnitude(a))
print(mag)
