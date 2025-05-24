"""
Create an account on NEWSAPI then get an API key from there. Install a package 'pywin32'. Read 10 updated daily news using the following function.
def read(str):
    from win32com.client import Dispatch
    read = Dispatch("SAPI.SpVoice")
    read.Speak(str)
"""

import requests
import json

def read(str):
    from win32com.client import Dispatch
    read = Dispatch("SAPI.SpVoice")
    read.Speak(str)

def news():
    res = requests.get("https://newsapi.org/v2/top-headlines?country=us&category=business&apiKey=31b5a0d59641438a9fd40b84d5f567d4")
    data = res.text
    parsed = json.loads(data)
    total_articles = len(parsed['articles'])
    for i in range (min(10, total_articles)):
        # printing and reading all trending news
        print(i + 1, end=")  ")
        read(f"{i + 1}")
        print(parsed['articles'][i]['title'])
        read(parsed['articles'][i]['title'])

if __name__ == '__main__':
    news()

print("Now you can choose the news that you love")

query = input("What news you want to listen? ")
url = f"https://newsapi.org/v2/everything?q={query}&from=2024-08-21&sortBy=publishedAt&apiKey=31b5a0d59641438a9fd40b84d5f567d4"
r = requests.get(url)
news = json.loads(r.text)
i = 0
for article in news["articles"]:
    print(article["title"])
    print(article["description"])
    print("-------------------------------")
    read(f"{i + 1}")
    read(article["title"])
    read(article["description"])
    i += 1