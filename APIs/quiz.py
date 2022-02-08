#basic algo ->getting questions done and correct answers stuff done, scoring algo not yet coded
import requests
import json
import random 

url = "https://opentdb.com/api.php?amount=10&category=18&difficulty=easy&type=multiple"
response = requests.get(url)

some_list = response.json()['results']

for data in some_list:
    print(data['question'])
    crt_ans = data['correct_answer']
    data['incorrect_answers'].append(data['correct_answer'])
    random.shuffle(data['incorrect_answers'])
    c = 1
    for i in data['incorrect_answers']:
        print(str(c) + ". " + i)
        c = c+1
    print()
    print("enter your answer: ")
    ans = int(input())
    
    if data['incorrect_answers'][ans-1] == crt_ans:
        print("correct answer mate cheers")

    else:
        print("wrong answer mate, you suck")