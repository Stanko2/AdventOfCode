def parseSet(s):
    a = s.split(',')
    out = {}
    for i in a:
        b = i.split(' ')
        out[b[2]] = int(b[1])
    return out

red = 12
green = 13
blue = 14
ans = 0
ans2 = 0
while True:
    line = input().split(':')
    if line[0] == 'END':
        break
    line[1].replace(', ',',')
    line[1].replace('; ',';')
    id = int(line[0].split(' ')[1])
    sets = line[1].split(';')
    funguje = True
    maxColors = [0,0,0]
    for i in range(len(sets)):
        sets[i] = parseSet(sets[i])
        for j in sets[i].keys():
            if j == 'red':
                maxColors[0] = max(maxColors[0],sets[i][j])
            elif j == 'green':
                maxColors[1] = max(maxColors[1],sets[i][j])
            elif j == 'blue':
                maxColors[2] = max(maxColors[2],sets[i][j])
            if j == 'red' and sets[i][j] > red:
                funguje = False
            elif j == 'green' and sets[i][j] > green:
                funguje = False
            elif j == 'blue' and sets[i][j] > blue:
                funguje = False
    ans2 += maxColors[0]*maxColors[1]*maxColors[2]
    if funguje:
        ans += id

print(ans)
print(ans2)