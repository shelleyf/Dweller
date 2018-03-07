

function jsonConvert(jsonString){
    var json = JSON.parse(jsonString);
    //console.log("json convert: "+json.HouseMap[0].Type);
    //console.log(json.HouseMap.length);
    var objArray = [];
    for(var i=0; i<json.HouseMap.length; i++){
        if(json.HouseMap[i].Type === "Device"){
            objArray[i] = new DeviceObj(json.HouseMap[i]);
        }else if(json.HouseMap[i].Type === "Door"){
            objArray[i] = new DoorObj(json.HouseMap[i]);
        }else if(json.HouseMap[i].Type === "Wall"){
            objArray[i] = new WallObj(json.HouseMap[i]);
        }else if(json.HouseMap[i].Type === "Floor"){
            objArray[i] = new FloorObj(json.HouseMap[i]);
        }else if(json.HouseMap[i].Type === "Window"){
            objArray[i] = new WindowObj(json.HouseMap[i]);
        }else{
            console.log("cant recognize this house item");
        }
    }
    return objArray;
}

function DeviceObj(data){
    this.type = data.Type;
    this.name = data.Name;
    this.positionTLX = data.PositionTL.x;
    this.positionBRX = data.PositionBR.x;
    this.positionTLY = data.PositionTL.y;
    this.positionBRY = data.PositionBR.y;
}

function DoorObj(data){
    this.type = data.Type;
    this.name = data.Name;
    this.positionStartX = data.PositionStart.x;
    this.positionStartY = data.PositionStart.y;
    this.positionEndX = data.PositionEnd.x;
    this.positionEndY = data.PositionEnd.y;
    this.doorHeight = data.DoorHeight;
    this.doorLeakage = data.DoorLeakage;
}

function WallObj(data){
    this.type = data.Type;
    this.name = data.Name;
    this.positionStartX = data.PositionStart.x;
    this.positionStartY = data.PositionStart.y;
    this.positionEndX = data.PositionEnd.x;
    this.positionEndY = data.PositionEnd.y;
    this.wallThickness = data.WallThickness;
}

function FloorObj(data){
    this.type = data.Type;
    this.name = data.Name;
    this.pointNum = data.PositionPoint.length;
    this.points = data.PositionPoint;
    this.data = data;
    console.log(data.PositionPoint["Point"+0].x);
//    for(var i=0;i<data.PositionPoint.length;i++){
//        this.positionPointX[i] = data.PositionPoint["Point"+i].x;
//        this.positionPointY[i] = data.PositionPoint["Point"+i].y;
//    }
}

function WindowObj(data){
    this.type = data.Type;
    this.name = data.Name;
    this.positionStartX = data.PositionStart.x;
    this.positionStartY = data.PositionStart.y;
    this.positionEndX = data.PositionEnd.x;
    this.positionEndY = data.PositionEnd.y;
    this.windowLeakage = data.WindowLeakage;
    this.windowHeight = data.WindowHeight;
    this.windowBottomHeight = data.WindowBottomHeight;
}
