import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/olhamelnyk/colcon_venv/src/install/recording_scene_bag'
