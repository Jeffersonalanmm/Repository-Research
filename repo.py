import requests
from bs4 import BeautifulSoup
import re
from collections import defaultdict

# URL arquivada da categoria de tarefas
BASE_URL = "https://web.archive.org/web/20241011063336/https://rosettacode.org"
TASKS_URL = f"{BASE_URL}/wiki/Category:Solutions_by_Programming_Task"

def get_task_links():
    task_links = []
    next_page = TASKS_URL
    while next_page:
        print(f"Coletando: {next_page}")
        resp = requests.get(next_page)
        soup = BeautifulSoup(resp.content, 'html.parser')

        # Coleta links das tasks
        links = [link for link in soup.select("#mw-pages a") if link['href'].startswith('/wiki/') and not 'pagefrom=' in link['href']]
        task_links.extend([BASE_URL + link['href'] for link in links if link['href'].startswith('/wiki/')])

        # Verifica próxima página
        next_link = soup.find('a', string='next page')
        next_page = "https://web.archive.org" + next_link['href'] if next_link else None

    return task_links

def count_implementations(task_url):
    resp = requests.get(task_url)
    soup = BeautifulSoup(resp.content, 'html.parser')

    content = soup.find("div", {"id": "mw-content-text"})
    headers = content.find_all(['h2', 'h3'])
    langs = set()

    for header in headers:
        span = header.find('span', {'class': 'mw-headline'})
        if span and not span.text.lower().startswith("see also"):
            langs.add(span.text.strip())

    print(f"Tarefa: {task_url} — {len(langs)} linguagens")  # debug aqui
    return len(langs), langs


def main():
    task_links = get_task_links()
    task_data = []

    for url in task_links:
        try:
            count, langs = count_implementations(url)
            task_data.append({
                'url': url,
                'count': count,
                'langs': langs
            })
        except Exception as e:
            print(f"Erro em {url}: {e}")

    # Filtra: pelo menos 20 implementações
    filtered = [task for task in task_data if task['count'] >= 20]

    print(f"\nTarefas com >= 20 implementações: {len(filtered)}\n")
    for task in filtered:
        print(f"{task['url']} — {task['count']} linguagens")

if __name__ == "__main__":
    main()
