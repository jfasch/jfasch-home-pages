import tempfile
import shutil
import os
import tarfile

with tempfile.TemporaryDirectory() as tmpd:
    subdir = tmpd + '/os-credentials'
    os.mkdir(subdir)
    shutil.copy('/etc/passwd', subdir)
    shutil.copy('/etc/group', subdir)

    tarname = tmpd + 'os-credentials.tar.bz2'
    with tarfile.open(tarname, 'w') as tf:
        tf.add(subdir, 'os-credentials')

    shutil.copy(tarname, os.path.expandvars('$HOME/os-credentials.tar.bz2'))
