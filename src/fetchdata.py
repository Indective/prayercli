import requests
import json

def makerequest(date, city):
    url = f"https://api.aladhan.com/v1/timingsByAddress/{date}?address={city}&method=4"  

    try:
        response = requests.get(url)
        response.raise_for_status() 

        data = response.json()
        print(json.dumps(data["data"]["timings"]))

    except requests.exceptions.RequestException as e:
        print(f"An error occurred: {e}")
        return None  