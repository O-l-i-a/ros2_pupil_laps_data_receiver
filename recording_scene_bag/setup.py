from setuptools import find_packages, setup

package_name = "recording_scene_bag"

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
    description="Scene recorder via ros2 bag with post-conversion to mp4+csv",
    license="Apache-2.0",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "recording_scene_bag = recording_scene_bag.recording_scene_bag:main",
        ],
    },
)
