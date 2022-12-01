elves = []
cal = 0
while True:
    a = input()
    if a == "end":
        elves.append(cal)
        break
    if a == "":
        elves.append(cal)
        cal = 0
        continue
    a = int(a)
    cal += a

elves.sort(reverse=True)
print(elves[0] + elves[1] + elves[2])