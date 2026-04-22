#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
if [[ -d "$SCRIPT_DIR/install" && -d "$SCRIPT_DIR/src" ]]; then
  WS_ROOT="$SCRIPT_DIR"
elif [[ -d "$SCRIPT_DIR/../install" && -d "$SCRIPT_DIR/../src" ]]; then
  WS_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
else
  echo "Could not detect workspace root from SCRIPT_DIR=$SCRIPT_DIR" >&2
  exit 1
fi
PID_FILE="$WS_ROOT/.recording_stack.pids"

cleanup_fastdds_shm() {
  rm -f /dev/shm/fastrtps_* /dev/shm/fastdds_* 2>/dev/null || true
}

signal_from_pid_file() {
  local sig="$1"
  tac "$PID_FILE" | while read -r name pid; do
    if [[ -z "${name:-}" || -z "${pid:-}" ]]; then
      continue
    fi
    if [[ ! "$pid" =~ ^[0-9]+$ ]]; then
      continue
    fi
    if kill -0 "$pid" >/dev/null 2>&1; then
      echo "$sig -> $name ($pid / group $pid)"
      kill "-$sig" "--" "-$pid" >/dev/null 2>&1 || kill "-$sig" "$pid" >/dev/null 2>&1 || true
    fi
  done
}

if [[ ! -f "$PID_FILE" ]]; then
  echo "No PID file found ($PID_FILE). Nothing else to stop."
  exit 0
fi

echo "Stopping launched processes from PID file..."
signal_from_pid_file INT

sleep 2

signal_from_pid_file TERM

sleep 2

signal_from_pid_file KILL

rm -f "$PID_FILE"
echo "Cleaning stale DDS shared-memory locks..."
cleanup_fastdds_shm
echo "Done."
