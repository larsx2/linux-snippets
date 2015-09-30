import contextlib
import os

r, w = os.pipe()

with contextlib.nested(
        os.fdopen(r), os.fdopen(w, 'w', 0)) as (rd, wr):

    hello, world = "Hello", "World!"

    wr.write(hello)

    print rd.read(len(hello)),

    wr.write(world)

    print rd.read(len(world))
