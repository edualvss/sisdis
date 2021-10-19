import requests

# Fake
api_url = "https://jsonplaceholder.typicode.com/todos"

# GET
response = requests.get(api_url+"/1")
print(response.json())
print(response.status_code)
print(response.headers["Content-Type"])


# POST
tarefa = {"userId":1, "title": "Comprar leite", "completed": False} # Dado a ser enviado
response = requests.post(api_url,json=tarefa)
print(response.json())
print(response.status_code)
