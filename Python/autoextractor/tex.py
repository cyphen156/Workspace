import os
import subprocess

# ktools 폴더 경로 설정
ktools_path = r"C:\Users\cyphen\Downloads\ktools\anim"

# ktech.exe 파일의 절대 경로
ktech_path = r"C:\Users\cyphen\Downloads\ktools\ktech.exe"

# 각 서브폴더에 대해 반복 처리
for folder_name in os.listdir(ktools_path):
    folder_path = os.path.join(ktools_path, folder_name)

    # 폴더인지 확인 (파일은 건너뜀)
    if not os.path.isdir(folder_path):
        print(f"Skipping {folder_name}, not a folder.")
        continue

    # atlas-0.tex 파일 경로 설정
    tex_file_path = os.path.join(folder_path, "atlas-0.tex")
    ktex_output_path = os.path.join(folder_path, "ktexOutput")

    # ktexOutput 폴더가 없으면 생성
    if not os.path.exists(ktex_output_path):
        os.makedirs(ktex_output_path)

    # TEX 파일이 존재하는지 확인 후 처리
    if os.path.exists(tex_file_path):
        # ktech 실행
        print(f"Extracting TEX file in {folder_name} with ktech...")
        subprocess.run([ktech_path, tex_file_path, ktex_output_path])
    else:
        print(f"Skipping {folder_name}, TEX file not found.")
