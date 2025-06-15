from setuptools import find_packages, setup

package_name = 'zed_mini'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=[ 'setuptools',
        'rclpy',
        'sensor_msgs',
        'visualization_msgs',
        'cv_bridge',
        'pyzed-sl'   ],
    zip_safe=True,
    maintainer='olhamelnyk',
    maintainer_email='olgamelnik12@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'zed_mini = zed_mini.zed_mini:main'
        ],
    },
)
