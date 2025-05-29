import os
from codecarbon import EmissionsTracker
import subprocess
import pandas as pd  # <- Adiciona isso para ler o CSV

os.makedirs("emissoes", exist_ok=True)

# Caminhos corrigidos
java_file_path = "../Java/llama-3.3-70b-versatile/llama_3_3_70b_versatile.java"
class_path = "../Java/llama-3.3-70b-versatile"
class_name = "llama_3_3_70b_versatile"

# Verifica se o arquivo .java existe
assert os.path.exists(java_file_path), f"Arquivo .java não encontrado: {java_file_path}"

# Inicia rastreamento
tracker = EmissionsTracker(output_dir="emissoes", output_file="java.csv")
tracker.start()

# Compila o arquivo Java
subprocess.run(["javac", java_file_path], check=True)

# Executa a classe compilada
subprocess.run(["java", "-cp", class_path, class_name], check=True)

# Encerra rastreamento
tracker.stop()

csv_path = os.path.join("emissoes", "java.csv")
df = pd.read_csv(csv_path)

ultima_execucao = df.iloc[-1]
emissao = ultima_execucao["emissions"]

print(f"Estimated CO₂ emissions: {emissao:.10f} kg")
