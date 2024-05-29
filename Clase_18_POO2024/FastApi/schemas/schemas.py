def individual_serializer(user) -> dict:
    return {
        "id": str(user["_id"]),
        "name": user["name"],
        "lastname": user["lastname"],
        "email": user["email"],
        "password": user["password"]
    }

def list_serial(users) -> list:
    return(individual_serializer(user) for user in users)