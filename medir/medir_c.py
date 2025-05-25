import os
from codecarbon import EmissionsTracker
import subprocess

# Garante que a pasta 'emissoes' exista
os.makedirs("emissoes", exist_ok=True)

tracker = EmissionsTracker(output_dir="emissoes", output_file="c.csv")
tracker.start()

# Executa o código Python
subprocess.run(["c", "C\gemma2-9b-it.c"])

tracker.stop()
