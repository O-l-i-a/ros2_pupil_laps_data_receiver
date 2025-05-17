from setuptools import find_packages
from setuptools import setup

setup(
    name='egocentric_msg',
    version='0.0.0',
    packages=find_packages(
        include=('egocentric_msg', 'egocentric_msg.*')),
)
