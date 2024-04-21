import os
folder_path = "K:\Lab"

for root, dirs, files in os.walk(folder_path):
    for filename in files:
        if filename.lower() == "desktop.ini":
            file_path = os.path.join(root, filename)
            try:
                os.remove(file_path)
                print(f"Deleted {file_path}")
            except Exception as e:
                print(f"Error deleting {file_path}: {e}")