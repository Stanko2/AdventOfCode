best = 0
cal = 0
while True:
    a = input()
    if a == "end":
        best = max(best, cal)
        break
    if a == "":
        best = max(best, cal)
        cal = 0
        continue
    a = int(a)
    cal += a

print(best)