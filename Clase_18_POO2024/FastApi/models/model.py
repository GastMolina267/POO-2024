from pydantic import BaseModel

class User(BaseModel):
    nombre: str
    apellido: str
    edad: int
    email: str