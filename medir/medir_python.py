import os
from codecarbon import EmissionsTracker
import subprocess
import pandas as pd

os.makedirs("emissoes", exist_ok=True)

tracker = EmissionsTracker(output_dir="emissoes", output_file="python.csv")
tracker.start()

# Caminho relativo correto para o script Python a ser executado
python_script_path = "../Python/gemma2-9b-it/gemma2-9b-it.py"

# Executa o script Python
subprocess.run(["python", python_script_path], check=True)

tracker.stop()

# Lê o CSV e pega a última emissão registrada
csv_path = os.path.join("emissoes", "c.csv")
df = pd.read_csv(csv_path)

ultima_execucao = df.iloc[-1]
emissao = ultima_execucao["emissions"]

print(f"Estimated CO₂ emissions: {emissao:.10f} kg")