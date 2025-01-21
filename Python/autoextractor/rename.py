import os
import re
import shutil

def clean_file_names(directory):
    """
    Clean and normalize file names in the given directory.
    - Removes " #숫자" at the end of file names (if present).
    - Converts "Slash_back_X" to "SlashBack_X".
    - Converts "Slash_Front_X" to "SlashFront_X".

    Args:
        directory (str): Path to the directory containing files.
    """
    files = [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]
    for file_name in files:
        old_path = os.path.join(directory, file_name)

        # Step 1: Remove " #숫자" at the end of the file name (before extension)
        new_name = re.sub(r" #\d+", "", file_name)  # Matches " #숫자"

        # Step 2: Normalize "Slash_back" and "Slash_Front" naming patterns
        new_name = new_name.replace("Slash_back_", "SlashBack_")
        new_name = new_name.replace("Slash_Front_", "SlashFront_")

        new_path = os.path.join(directory, new_name)

        # Rename the file if the name has changed
        if old_path != new_path:
            os.rename(old_path, new_path)
            print(f"Renamed: {file_name} -> {new_name}")
        else:
            print(f"No change needed for: {file_name}")


def organize_files_into_folders(directory):
    """
    Organize files into folders based on their file name prefixes.

    Args:
        directory (str): Path to the directory containing files.
    """
    files = [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]
    for file_name in files:
        file_path = os.path.join(directory, file_name)

        # Extract the prefix from the file name (e.g., "SlashBack", "AttackA", etc.)
        prefix = file_name.split("_")[0]  # Get text before the first "_"
        folder_path = os.path.join(directory, prefix)

        # Create the folder if it doesn't exist
        if not os.path.exists(folder_path):
            os.makedirs(folder_path)

        # Move the file into the appropriate folder
        shutil.move(file_path, os.path.join(folder_path, file_name))
        print(f"Moved: {file_name} -> {folder_path}")


def process_all_types(root_directory):
    """
    Process all types, characters, and levels under the root directory.
    Clean file names and organize files into folders.

    Args:
        root_directory (str): Path to the root directory containing type folders.
    """
    for type_name in os.listdir(root_directory):  # Iterate through 'type' folders
        type_path = os.path.join(root_directory, type_name)
        if not os.path.isdir(type_path):
            continue

        for character in os.listdir(type_path):  # Iterate through 'character' folders
            character_path = os.path.join(type_path, character)
            if not os.path.isdir(character_path):
                continue

            # Iterate through level folders (e.g., LV1, LV2, ...)
            for level in os.listdir(character_path):
                level_path = os.path.join(character_path, level)
                if not os.path.isdir(level_path):
                    continue

                print(f"Processing: {type_name}/{character}/{level}")

                # Step 1: Clean file names in the current level folder
                clean_file_names(level_path)

                # Step 2: Organize files into folders
                organize_files_into_folders(level_path)


if __name__ == "__main__":
    root_directory = "D:/Name/skuls"  # 'skuls' 폴더 경로
    process_all_types(root_directory)
