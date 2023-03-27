#!/usr/bin/env python

import numpy
import PIL.Image
from sklearn.cluster import KMeans

import sys


img = PIL.Image.open('veggie.png')

imgarray = numpy.array(img)
nrows, ncols, nrgba = imgarray.shape

# disregard alpha plane for clustering
alpha = imgarray[:,:,3:]
rgb = imgarray[:,:,0:3]

# change view to a linear sequence of (r,g,b) points. (K-Means cannot
# take arbitrarily dimensioned spaces, he likes it linear.)
linear_rgb = rgb.reshape((nrows*ncols, 3))

km = KMeans(n_clusters=8)
km.fit(linear_rgb)

# reduce: let cluster centers be their members
for idx, label in enumerate(km.labels_):
    linear_rgb[idx] = km.cluster_centers_[label]

# stack saved alpha plane on top of it
imgarray = numpy.concatenate((rgb, alpha), axis=2)

reduced_img = PIL.Image.fromarray(imgarray, 'RGBA')
reduced_img.save('veggie-reduced.png')
