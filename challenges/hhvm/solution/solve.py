#!/usr/bin/env python3

import requests

with requests.Session() as session:
    response = requests.post('http://localhost:8000/', data={"username": "user", "password": "QNKCDZO"})
    print(response.text)
