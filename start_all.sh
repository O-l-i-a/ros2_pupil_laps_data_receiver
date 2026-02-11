#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WS_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

LOG_DIR="$WS_ROOT/runtime_logs"
PID_FILE="$WS_ROOT/.recording_stack.pids"

mkdir -p "$LOG_DIR"

if [[ -f "$PID_FILE" ]]; then
  echo "PID file already exists: $PID_FILE"
  echo "If stack is not running, remove it or run ./stop_all.sh first."
  exit 1
fi

touch "$PID_FILE"

launch_node() {
  local name="$1"
  local command="$2"

  echo "Launching $name"
  nohup bash -lc "$command" >"$LOG_DIR/$name.log" 2>&1 &
  local pid=$!
  echo "$name $pid" >>"$PID_FILE"
  sleep 0.6
}

# 1) ZED
launch_node "zed_ipc" "
  cd '$WS_ROOT' &&
  source '$WS_ROOT/install/setup.bash' &&
  taskset -c 0-7 ros2 launch zed_ipc zed_ipc.launch.py cam_names:=[myzed2i] cam_models:=[zed2i] cam_serials:=[37866365] cam_ids:=[0]
"

# 2) Pupil wrapper
launch_node "async_pupil_wrapper" "
  cd '$WS_ROOT' &&
  source '$WS_ROOT/venv/bin/activate' &&
  source /opt/ros/jazzy/setup.bash &&
  export PYTHONPATH='$WS_ROOT/venv/lib/python3.12/site-packages':\$PYTHONPATH &&
  source '$WS_ROOT/install/setup.bash' &&
  taskset -c 8-11 ros2 run async_pupil_wrapper async_pupil_wrapper
"

# 3) Scene bag recorder + other recorders
launch_node "recording_scene_bag" "
  cd '$WS_ROOT' &&
  source '$WS_ROOT/install/setup.bash' &&
  taskset -c 12-15 ros2 run recording_scene_bag recording_scene_bag
"

launch_node "recording_gaze" "
  cd '$WS_ROOT' &&
  source '$WS_ROOT/install/setup.bash' &&
  taskset -c 12-15 ros2 run recording_gaze recording_gaze
"

launch_node "recording_blink" "
  cd '$WS_ROOT' &&
  source '$WS_ROOT/install/setup.bash' &&
  taskset -c 12-15 ros2 run recording_blink recording_blink
"

launch_node "recording_imu" "
  cd '$WS_ROOT' &&
  source '$WS_ROOT/install/setup.bash' &&
  taskset -c 12-15 ros2 run recording_imu recording_imu
"

# 4) Controller GUI
launch_node "recording_controller" "
  cd '$WS_ROOT' &&
  source '$WS_ROOT/install/setup.bash' &&
  taskset -c 12-15 ros2 run recording_controller_pkg controller_node
"

echo
echo "All processes launched."
echo "Logs: $LOG_DIR"
echo "PIDs: $PID_FILE"
echo "Use ./stop_all.sh to stop everything cleanly."
