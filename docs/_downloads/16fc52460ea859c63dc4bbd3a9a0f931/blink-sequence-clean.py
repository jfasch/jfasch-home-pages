#!/usr/bin/env python

from stuff_raw2 import *
import asyncio
import numpy

async def main():
    cols = numpy.transpose(MATRIX).tolist()

    await sequence([
        blink(cols[0], 0.5, 2),
        blink(cols[1], 0.4, 2),
        blink(cols[2], 0.3, 2),
        blink(cols[3], 0.2, 2),
        blink(cols[4], 0.1, 2),
    ])

asyncio.run(main())
