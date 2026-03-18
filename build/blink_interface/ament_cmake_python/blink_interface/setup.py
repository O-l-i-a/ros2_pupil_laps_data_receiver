from setuptools import find_packages
from setuptools import setup

setup(
    name='blink_interface',
    version='0.0.0',
    packages=find_packages(
        include=('blink_interface', 'blink_interface.*')),
)
