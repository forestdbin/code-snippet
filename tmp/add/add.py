import random

def A():
    result = []
    while len(result) != 10:
        a = random.randint(1, 8)
        b = random.randint(1, 9 - a)
        if (a, b) not in result:
            result.append((a, b))
    for a, b in result[:5]:
        print('%2d + %2d = ' % (a, b))
    for a, b in result[5:]:
        print('%2d - %2d = ' % (a + b, a))

def B():
    questions = [ (1, 9), (2, 8), (3, 7), (4, 6), (5, 5),
                  (6, 4), (7, 3), (8, 2), (9, 1), ]
    random.shuffle(questions)
    for a, b in questions[:5]:
        print('%2d + %2d = ' % (a, b))
    for a, b in questions[4:]:
        print('%2d - %2d = ' % (a + b, a))

def C():
    result = []
    while len(result) != 10:
        a = random.randint(2, 9)
        b = random.randint(11 - a, 9)
        if (a, b) not in result:
            result.append((a, b))
    for a, b in result[:5]:
        print('%2d + %2d = ' % (a, b))
    for a, b in result[5:]:
        print('%2d - %2d = ' % (a + b, a))

def D():
    result = []
    while len(result) != 10:
        a = random.randint(1, 8)
        b = random.randint(1, 9 - a)
        if (a, b) not in result:
            result.append((a, b))
    for a, b in result[:5]:
        print('%2d + %2d = ' % ((10 + a, b) if random.randint(1, 2) == 1 else (a, 10 + b)))
    for a, b in result[5:]:
        print('%2d - %2d = ' % (10 + a + b, a))

if __name__ == '__main__':
    random.seed()
    A()
    B()
    C()
    D()
