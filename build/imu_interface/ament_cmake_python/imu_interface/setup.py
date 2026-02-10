from setuptools import find_packages
from setuptools import setup

setup(
    name='imu_interface',
    version='0.0.0',
    packages=find_packages(
        include=('imu_interface', 'imu_interface.*')),
)
