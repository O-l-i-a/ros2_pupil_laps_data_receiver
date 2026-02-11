#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WS_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
PID_FILE="$WS_ROOT/.recording_stack.pids"

stop_service() {
  local service="$1"
  local value="$2"
  timeout 3s bash -lc "
    cd '$WS_ROOT' &&
    source '$WS_ROOT/install/setup.bash' &&
    ros2 service call '$service' std_srvs/srv/SetBool \"{data: $value}\"
  " >/dev/null 2>&1 || true
}

echo "Requesting graceful stop via services..."
stop_service "/zed_multi/record_zed_depth" false
stop_service "/zed_multi/record_zed_rgb" false
stop_service "/record_pupil_scene_bag" false
stop_service "/record_pupil_scene" false
stop_service "/record_pupil_gaze" false
stop_service "/record_pupil_blink" false
stop_service "/record_pupil_imu" false

if [[ ! -f "$PID_FILE" ]]; then
  echo "No PID file found ($PID_FILE). Nothing else to stop."
  exit 0
fi

echo "Stopping launched processes..."
tac "$PID_FILE" | while read -r name pid; do
  if [[ -z "${pid:-}" ]]; then
    continue
  fi
  if kill -0 "$pid" >/dev/null 2>&1; then
    echo "SIGINT -> $name ($pid)"
    kill -INT "$pid" >/dev/null 2>&1 || true
  fi
done

sleep 2

tac "$PID_FILE" | while read -r name pid; do
  if [[ -z "${pid:-}" ]]; then
    continue
  fi
  if kill -0 "$pid" >/dev/null 2>&1; then
    echo "SIGTERM -> $name ($pid)"
    kill -TERM "$pid" >/dev/null 2>&1 || true
  fi
done

sleep 2

tac "$PID_FILE" | while read -r name pid; do
  if [[ -z "${pid:-}" ]]; then
    continue
  fi
  if kill -0 "$pid" >/dev/null 2>&1; then
    echo "SIGKILL -> $name ($pid)"
    kill -KILL "$pid" >/dev/null 2>&1 || true
  fi
done

rm -f "$PID_FILE"
echo "Done."
