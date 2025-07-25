import shutil
import subprocess
from pathlib import Path
import sys

def convert_and_copy_folder(src_folder: str, dst_folder: str) -> None:
    """
    Convert all .avi files in src_folder to .mp4 (video-only, no audio)
    and copy all other files unchanged into dst_folder.

    Requirements:
      - ffmpeg muss installiert und in PATH sein.
    """
    src = Path(src_folder)
    dst = Path(dst_folder)
    dst.mkdir(parents=True, exist_ok=True)

    for file in src.iterdir():
        if not file.is_file():
            continue

        if file.suffix.lower() == '.avi':
            out_file = dst / (file.stem + '.mp4')
            print(f"Konvertiere {file} → {out_file} …")
            subprocess.run([
                "ffmpeg", "-i", str(file),
                "-c:v", "libx264", "-preset", "slow", "-crf", "18",
                "-pix_fmt", "yuv420p", "-an", "-movflags", "+faststart",
                str(out_file)
            ], check=True)
        else:
            dest_path = dst / file.name
            print(f"Kopiere {file} → {dest_path} …")
            shutil.copy2(file, dest_path)

def main():
    # expect between 2 and 10 positional args (i.e. 1–5 pairs)
    args = sys.argv[1:]
    n = len(args)
    if n < 2 or n % 2 != 0 or n > 10:
        print("Usage: python convert.py src1 dst1 [src2 dst2 ... up to 5 pairs]")
        sys.exit(1)

    # process each pair
    for i in range(0, n, 2):
        src, dst = args[i], args[i+1]
        print(f"\n=== Verarbeitung von {src} → {dst} ===")
        convert_and_copy_folder(src, dst)

if __name__ == "__main__":
    main()
