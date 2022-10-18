import random
import time

startgen = time.time()
liste = []
for i in range(100000000):
    liste.append(random.randint(1, 100000000))

endgen = time.time()
print(endgen - startgen)

startsort = time.time()

liste.sort()

endsort = time.time()

print(endsort - startsort)
