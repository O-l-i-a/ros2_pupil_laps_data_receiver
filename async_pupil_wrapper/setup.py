from setuptools import find_packages, setup

package_name = 'async_pupil_wrapper'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'setuptools',
        'pupil-labs-realtime-api',],
    zip_safe=True,
    maintainer='olhamelnyk',
    maintainer_email='olgamelnik12@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'async_pupil_wrapper = async_pupil_wrapper.async_pupil_wrapper:main',
            'scene_time_publisher = async_pupil_wrapper.scene_time_publisher:main',
        ],
    },
)
