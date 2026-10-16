from typing import Optional

from fastapi import FastAPI
from fastapi import Request


class deprecataed:
    """Simple deprecation helper with a useful message."""

    def __init__(self, message: str = "This endpoint is deprecated.", replacement: Optional[str] = None):
        self.message = message
        self.replacement = replacement

    def get_message(self) -> str:
        if self.replacement:
            return f"{self.message} Use '{self.replacement}' instead."
        return self.message

    def get_warning(self) -> dict:
        return {
            "deprecated": True,
            "message": self.get_message(),
            "replacement": self.replacement,
        }


app=FastAPI(
    title="about summit api",
    version="1.0.0",
    description="this is a simple api that tell about summit",
    docs_url="/docs",
    redoc_url="/redoc",
    openapi_url="/openapi.json",
)
@app.get("/")
def read():
    """simple function to return hello summit  """
    return {"message":"hello sumit","status":200}

@app.get("/about")
def about():
    """ simple function that tell about summit"""
    return {"message":"i am summit i am just a human try do thing that afraid  me","status":"being not okey is okey"}
@app.get("/hru")
def respond():
    """simple function to return how are you"""
    return {"message":"i am finne sir you are do good sir","status":200}


@app.get("/request_info",
         summary="request information",
         description="this function return request information like client host,client port like every thing about request",
         tags=["request information"],
         deprecated=False)
async def request_info(req:Request):
   """if description not work it mean function to return request information"""
   deprecation = deprecataed(
       message="This endpoint is deprecated. Prefer the supported route metadata instead.",
       replacement="/about",
   )
   return{
      "client_host":req.client.host,
        "client_port":req.client.port,
        "url":str(req.url),
        "headers":dict(req.headers),
        "method":req.method,
        "path":req.url.path,
        "query_params":dict(req.query_params),
        "deprecation": deprecation.get_warning(),
   }
