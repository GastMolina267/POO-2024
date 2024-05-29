from pymongo import MongoClient

client = MongoClient("mongodb://localhost:27017")

db = client.local

collection_name = db["user"]