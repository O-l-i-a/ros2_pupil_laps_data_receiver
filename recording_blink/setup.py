from setuptools import find_packages, setup

package_name = "recording_blink"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="olhamelnyk",
    maintainer_email="olgamelnik12@gmail.com",
    description="Blink recorder node for Pupil ROS streams",
    license="Apache-2.0",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "recording_blink = recording_blink.recording_blink:main",
        ],
    },
)
