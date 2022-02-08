import requests
import json

response = requests.get("http://api.stackexchange.com//2.3/questions?order=desc&sort=activity&site=stackoverflow")


print(response.json()['items'])

for data in response.json()['items']:
    print(data['title'])