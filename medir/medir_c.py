import os
from codecarbon import EmissionsTracker
import subprocess
import pandas as pd

os.makedirs("emissoes", exist_ok=True)

tracker = EmissionsTracker(output_dir="emissoes", output_file="c.csv")
tracker.start()

c_file_path = "../C/gemma2-9b-it/gemma2-9b-it.c"
exe_path = "../C/gemma2-9b-it/gemma2-9b-it.exe"


# Compila o código C
subprocess.run(["gcc", c_file_path, "-o", exe_path], check=True)

# Executa o programa compilado
subprocess.run([exe_path], check=True)

tracker.stop()

# Lê o CSV e pega a última emissão registrada
csv_path = os.path.join("emissoes", "c.csv")
df = pd.read_csv(csv_path)

ultima_execucao = df.iloc[-1]
emissao = ultima_execucao["emissions"]

print(f"Estimated CO₂ emissions: {emissao:.10f} kg")
