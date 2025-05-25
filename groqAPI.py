import os
import json
from groq import Groq
import sys
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

with open("config.json", "r", encoding="utf-8") as config_file:
    config = json.load(config_file)
    api_key = config["api_key"]

client = Groq(api_key=api_key)
prompt = (
    "You are a software engineer specialized in software sustainability, data structure and algorithms.\n"
    "Provide the response in the following format:\n\n"
    "<code in the chosen programming language with 1000 random inputs and no use of prints>\n"
)

user = (
    "User: Write an optimized implementation of the <algorithm> in the programming language <language>?"
)

chat_completion = client.chat.completions.create(
    messages=[
        {"role": "system", "content": prompt},
        {"role": "user", "content": user.replace("<algorithm>", "Bubblesort algorithm").replace("<language>", "Java")},
    ],
    model="gemma2-9b-it",
    temperature=0,
)

print(chat_completion.choices[0].message.content)