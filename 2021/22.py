def get_intersect(a1, a2, b1, b2):
    if a1 < b1:
        if (a2 < b2):
            return None
        else:
            if a2 < b2:
                return (b1, a2)
            else:
                return (b1, b2)
    else:
        if b2 < a1:
            return None
        else:
            if b2 < a2:
                return (a1, b2)
            else:
                return (a1, a2)


class Box:
    def __init__(self, x1, x2, y1, y2, z1, z2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.z1 = z1
        self.z2 = z2
        self.on = True

    def volume(self):
        return (self.x2 - self.x1 + 1) * (self.y2 - self.y1 + 1) * (self.z2 - self.z1 + 1)

    def intersection(self, other):
        X = get_intersect(self.x1, self.x2, other.x1, other.x2)
        Y = get_intersect(self.y1, self.y2, other.y1, other.y2)
        Z = get_intersect(self.z1, self.z2, other.z1, other.z2)
        if X == None or Y == None or Z == None:
            return None
        return Box(X[0], X[1], Y[0], Y[1], Z[0], Z[1])


n = int(input())
boxes = []
for i in range(n):
    a = input().split()
    b = Box(int(a[1]), int(a[2]), int(a[3]), int(a[4]), int(a[5]), int(a[6]))
    b.on = a[0] == 'on'
    added = []
    for box in boxes:
        intersection = b.intersection(box)
        if intersection == None:
            continue
        intersection.on = not box.on
        added.append(intersection)
    boxes.extend(added)
    if b.on:
        boxes.append(b)

on = 0
for box in boxes:
    if box.on:
        on += box.volume()
    else:
        on -= box.volume()

print(on)
