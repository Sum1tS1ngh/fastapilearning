from typing import Optional
from fastapi import FastAPI,Query,HTTPException
from data import menu_items
from models import MenuItem,MenuResponse

app=FastAPI(
    title="chai pont menu api",
    description="read only menu that display on mobile display"
)

@app.get("/")
def welcome():
    return{
        "message":"welcome to chai poit have a good day"
    }
@app.get("/menu", response_model=MenuResponse)
def get_menu(category: Optional[str] = Query(None, description="Filter by chai, snack or combo")):
    if category:
        filterd=[item for item in menu_items if item["category"]==category]
        if not filterd:
            raise HTTPException(status_code=402,detail=f"{category} not find in menu")
        return MenuResponse(
            count=len(filterd),
            items=filterd
        )
    return MenuResponse(
            count=len(menu_items),
            items=menu_items
    )

@app.get("/menu/{item_id}",response_model=MenuItem)
def get_menu_item(item_id:int):
    for item in menu_items:
        if item["id"]==item_id:
            return item
    raise HTTPException(status_code=402, detail=f"item id {item_id}not find in menu")