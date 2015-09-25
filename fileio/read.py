import os
import sys

fd = os.open("test.txt", os.O_RDONLY)

data = os.read(fd, 20)

print data, len(data)

os.close(fd)
