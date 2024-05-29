from fastapi import FastAPI
from pymongo.mongo_client import MongoClient
from rutas import router

app = FastAPI()

url = "mongodb://localhost:27017"
client = MongoClient(url)
try:
    client.admin.command('ping')
    print("Conectado a la Base de Datos en MongoDB")
except Exception as e:
    print(e)

app.include_router(router)