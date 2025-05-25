import os
from codecarbon import EmissionsTracker
import subprocess

# Garante que a pasta 'emissoes' exista
os.makedirs("emissoes", exist_ok=True)

tracker = EmissionsTracker(output_dir="emissoes", output_file="python.csv")
tracker.start()

# Executa o código Python
subprocess.run(["python", "Python\gemma2-9b-it.py"])

tracker.stop()
