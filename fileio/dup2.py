import os
import sys

fd = os.open("foo.txt", os.O_RDWR | os.O_CREAT)

os.write(fd, "This is a test\n")

fd2 = 1000
os.dup2(fd, fd2)

os.lseek(fd2, 0, 0)
text = os.read(fd2, 100)

print "Read text is:", text

os.close(fd)

print "Closde the file successfully!"
