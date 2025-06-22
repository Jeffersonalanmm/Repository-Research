import os
import subprocess
import time
from datetime import datetime
import logging
import sys
from codecarbon import EmissionsTracker

# --- Configurações ---
# Diretórios contendo os scripts a serem medidos
DIRETORIOS_RAIZ = ['C', 'Java', 'Python']

# Diretório para salvar os logs gerados
DIRETORIO_LOGS = 'logs_codecarbon'

# Constante para cálculo de emissão anual
SEGUNDOS_EM_UM_ANO = 365.25 * 24 * 60 * 60

# --- Funções Auxiliares ---

def criar_diretorio_se_nao_existir(path):
    """Cria um diretório se ele ainda não existir."""
    if not os.path.exists(path):
        os.makedirs(path)

def executar_comando(comando, nome_script):
    """Executa um comando no shell e trata possíveis erros."""
    try:
        print(f"  > Executando: {' '.join(comando)}")
        subprocess.run(
            comando,
            check=True,
            capture_output=True,
            text=True
        )
        return True
    except subprocess.CalledProcessError as e:
        print(f"\n[ERRO] Falha ao executar comando para o script: {nome_script}")
        print(f"Comando: {' '.join(e.cmd)}")
        print(f"Stderr: {e.stderr}")
        return False
    except FileNotFoundError:
        print(f"\n[ERRO] Comando não encontrado: '{comando[0]}'. Verifique se ele está instalado e no PATH do sistema.")
        return False


def salvar_log(log_path, dados):
    """Salva o dicionário de dados em um arquivo de log formatado."""
    with open(log_path, 'w', encoding='utf-8') as f:
        f.write("--- Relatório de Consumo e Emissões (CodeCarbon) ---\n\n")
        for chave, valor in dados.items():
            f.write(f"{chave}: {valor}\n")
    print(f"\n[SUCESSO] Relatório salvo em: {log_path}")


def setup_codecarbon_logger():
    """Configura o logger do CodeCarbon para gerar o arquivo codecarbon.log."""
    # Remove o arquivo codecarbon.log se ele já existir
    if os.path.exists("codecarbon.log"):
        os.remove("codecarbon.log")

    logger = logging.getLogger("codecarbon")
    while logger.hasHandlers():
        logger.removeHandler(logger.handlers[0])

    # Define um formatador de log
    formatter = logging.Formatter(
        "%(asctime)s - %(name)-12s: %(levelname)-8s %(message)s"
    )

    # Cria um handler para arquivo que registra mensagens de debug
    fh = logging.FileHandler("codecarbon.log")
    fh.setLevel(logging.DEBUG)
    fh.setFormatter(formatter)
    logger.addHandler(fh)

    # Cria um handler para o console que registra mensagens de warning ou superior
    consoleHandler = logging.StreamHandler(sys.stdout)
    consoleHandler.setFormatter(formatter)
    consoleHandler.setLevel(logging.WARNING)
    logger.addHandler(consoleHandler)

    logger.debug("GO!")

def read_codecarbon_log():
    """Lê o conteúdo do arquivo codecarbon.log e retorna como uma string."""
    try:
        with open("codecarbon.log", "r") as log_file:
            return log_file.read()
    except FileNotFoundError:
        return "Arquivo codecarbon.log não encontrado."


def medir_execucao(compile_cmd, run_cmd, script_path):
    """Compila (se necessário) e mede a execução de um script com CodeCarbon."""
    script_filename = os.path.basename(script_path)
    print(f"\n--- Iniciando Medição para: {script_path} ---")

    # 1. Compilar (se necessário)
    if compile_cmd:
        print(f"\n[ETAPA 1/3] Compilando...")
        if not executar_comando(compile_cmd, script_filename):
            return # Pula para o próximo script se a compilação falhar

    # 2. Medir a execução com CodeCarbon
    print(f"\n[ETAPA 2/3] Executando e Medindo com CodeCarbon...")
    
    # Usamos um diretório temporário para os arquivos .csv padrão do codecarbon
    tracker_output_dir = os.path.join(os.getcwd(), 'temp_codecarbon_output')
    criar_diretorio_se_nao_existir(tracker_output_dir)

    tracker = EmissionsTracker(
        output_dir=tracker_output_dir,
        project_name=f"medicao_{script_filename.replace('.', '_')}",
        measure_power_secs=2, 
        tracking_mode="machine"
    )

    # Configura o logger do CodeCarbon
    setup_codecarbon_logger()

    # inicia tempo para calculo de duração
    start_time = datetime.now()


    tracker.start()
    sucesso_execucao = executar_comando(run_cmd, script_filename)
    emissions_data = tracker.stop()

    # finaliza tempo
    end_time = time.time()

    # Lê o conteúdo do arquivo codecarbon.log
    codecarbon_log = read_codecarbon_log()

    if not sucesso_execucao:
        print(f"[AVISO] A execução do script '{script_filename}' falhou. O log de emissões pode estar incompleto ou zerado.")
        return # Não gera log se o script principal falhou

    # 3. Gerar o Log customizado
    print(f"\n[ETAPA 3/3] Gerando Log Customizado...")
    
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    log_filename = f"{script_filename.replace('.', '_')}_{timestamp}.log"
    log_path = os.path.join(DIRETORIO_LOGS, log_filename)

    # # Cálculos
    # duration_sec = emissions_data.duration
    # emissions_kg = emissions_data.emissions
    
    # emissions_per_second = (emissions_kg / duration_sec) if duration_sec > 0 else 0
    # emissions_per_year = emissions_per_second * SEGUNDOS_EM_UM_ANO

    execution_time = end_time - start_time.timestamp()

    dados_log = {
        "Script Analisado": script_path,
        "Timestamp da Medição": datetime.now().isoformat(),
        "Emissões de carbono: ": emissions_data,
        "_total_cpu_energy": tracker._total_cpu_energy,
        "_cpu_power": tracker._cpu_power,
        "_emissions": tracker._emissions,
        "_total_energy": tracker._total_energy,
        "_geo": tracker._geo,
        "_log_level": tracker._log_level,
        "execution_time": execution_time,

        # "Emissão Anualizada (kg CO2eq/ano)": f"{emissions_per_year:.9f}",
        # "País (localização da medição)": f"{emissions_data.country_name} ({emissions_data.country_iso_code})",
        "codecarbon_log: ": codecarbon_log,
    }
    
    salvar_log(log_path, dados_log)


# --- Lógica Principal ---

def main():
    """Função principal que orquestra a medição de todos os scripts."""
    criar_diretorio_se_nao_existir(DIRETORIO_LOGS)
    arquivos_a_limpar = []

    try:
        for lang_dir in DIRETORIOS_RAIZ:
            if not os.path.isdir(lang_dir):
                print(f"[AVISO] Diretório '{lang_dir}' não encontrado. Pulando.")
                continue

            for root, _, files in os.walk(lang_dir):
                for file in files:
                    script_path = os.path.join(root, file)
                    compile_cmd = None
                    run_cmd = None
                    
                    # Definição dos comandos de compilação e execução por linguagem
                    if file.endswith('.c'):
                        executavel_path = script_path.rsplit('.', 1)[0]
                        compile_cmd = ['gcc', script_path, '-o', executavel_path, '-lm'] # -lm para linkar a lib matemática
                        run_cmd = [executavel_path]
                        arquivos_a_limpar.append(executavel_path)

                    elif file.endswith('.java'):
                        # -cp define o classpath para o diretório que contém a classe
                        # Java espera o nome da classe, não o nome do arquivo .java
                        class_name = file.rsplit('.', 1)[0]
                        compile_cmd = ['javac', script_path]
                        run_cmd = ['java', '-cp', root, class_name]
                        arquivos_a_limpar.append(os.path.join(root, f"{class_name}.class"))

                    elif file.endswith('.py'):
                        run_cmd = ['python3', script_path]

                    if run_cmd:
                        medir_execucao(compile_cmd, run_cmd, script_path)
                        print("-" * 50)

    finally:
        # Limpa os arquivos compilados (executáveis e .class)
        print("\n--- Finalizando e limpando arquivos temporários ---")
        for f in arquivos_a_limpar:
            if os.path.exists(f):
                try:
                    os.remove(f)
                    print(f"  > Removido: {f}")
                except OSError as e:
                    print(f"  > Erro ao remover {f}: {e}")
        # Limpa o diretório de CSVs do codecarbon
        if os.path.exists('temp_codecarbon_output'):
            for f in os.listdir('temp_codecarbon_output'):
                os.remove(os.path.join('temp_codecarbon_output', f))
            os.rmdir('temp_codecarbon_output')
            print("  > Diretório temporário do CodeCarbon limpo.")

if __name__ == '__main__':
    main()