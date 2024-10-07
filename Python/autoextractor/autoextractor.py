import os
import subprocess

# ktools 폴더 경로 설정
ktools_path = r"C:\Users\cyphen\Downloads\ktools\anim"

# krane.exe 파일의 절대 경로
krane_path = r"C:\Users\cyphen\Downloads\ktools\krane.exe"
ktech_path = r"C:\Users\cyphen\Downloads\ktools\ktech.exe"

# 각 서브폴더에 대해 반복 처리
for folder_name in os.listdir(ktools_path):
    folder_path = os.path.join(ktools_path, folder_name)

    # 폴더인지 확인 (파일은 건너뜀)
    if not os.path.isdir(folder_path):
        print(f"Skipping {folder_name}, not a folder.")
        continue

    # anim.bin, build.bin, atlas-0.tex 파일 경로 설정
    anim_path = os.path.join(folder_path, "anim.bin")
    build_path = os.path.join(folder_path, "build.bin")
    atlas_path = os.path.join(folder_path, "atlas-0.tex")
    output_path = os.path.join(folder_path, "Output")

    # 출력 폴더가 없으면 생성
    if not os.path.exists(output_path):
        os.makedirs(output_path)

    # 파일이 존재하는지 확인 후 처리
    if os.path.exists(anim_path) and os.path.exists(build_path):
        # krane 실행
        print(f"Processing {folder_name} with krane...")
        subprocess.run([krane_path, anim_path, build_path, output_path])
    else:
        print(f"Skipping {folder_name}, anim.bin or build.bin not found.")

    if os.path.exists(atlas_path):
        # ktech 실행
        print(f"Processing {folder_name} with ktech...")
        subprocess.run([ktech_path, atlas_path, output_path])
    else:
        print(f"Skipping {folder_name}, atlas-0.tex not found.")
