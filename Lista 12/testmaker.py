import string
import random

def random_char(y):
       return ''.join(random.choice(string.ascii_letters) for x in range(y))

print(random_char(60000))
