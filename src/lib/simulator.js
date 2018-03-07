Qt.include("/lib/qt-three.js/three.js-master/build/three.js")
Qt.include("/lib/qt-three.js/three.js-master/build/Detector.js")
Qt.include("/lib/qt-three.js/three.js-master/build/OrbitControls.js")
Qt.include("/lib/lib3d/JsonToHouseObject.js")

var camera, scene, renderer, mesh, controls, aspect;
var SCREEN_WIDTH, SCREEN_HEIGHT;
var textureLoader;
var clock;

var obj;
var objFromJson;

function log(message) {
    if (canvas3d.logAllCalls)
        console.log(message)
}

function initializeGL(canvas, eventSource, houseMap) {
    SCREEN_WIDTH = canvas.width;
    SCREEN_HEIGHT = canvas.height;
    aspect = SCREEN_WIDTH / SCREEN_HEIGHT;

    camera = new THREE.PerspectiveCamera( 50, 0.5 * aspect, 1, 10000 );
    camera.position.x = 510;
    camera.position.y = 500;//18;
    camera.position.z = 500;

    controls = new THREE.OrbitControls(camera, eventSource);
    clock = new THREE.Clock();

    renderer = new THREE.Canvas3DRenderer(
                { canvas: canvas3d, antialias: true, devicePixelRatio: canvas.devicePixelRatio });
    renderer.setPixelRatio( canvas.devicePixelRatio );
    renderer.setSize( canvas.width, canvas.height );

    scene = new THREE.Scene();

    textureLoader = new THREE.TextureLoader();
    var gridTexture = textureLoader.load("qrc:/res/texture/grid.png");
    gridTexture.wrapS = gridTexture.wrapT = THREE.RepeatWrapping;
    gridTexture.repeat.set(40,40);
    gridTexture.anisotropy = 16;

    var groundGeometry = new THREE.BoxGeometry(800,20,800,1,1,1);
    var groundMaterial = new THREE.MeshPhongMaterial({map:gridTexture});
    var ground = new THREE.Mesh(groundGeometry,groundMaterial);
    ground.position.x = 200;
    ground.position.y = -20;
    ground.position.z = 200;

    //ground.rotation.x = -Math.PI/2;
    scene.add(ground);

    var starGeometry = new THREE.Geometry();

    for (var i=0;i<10000;i++){
        var vertex = new THREE.Vector3();
        vertex.x = THREE.Math.randFloatSpread(2000)+50;
        vertex.y = THREE.Math.randFloatSpread(2000)+50;
        vertex.z = THREE.Math.randFloatSpread(2000)+50;

        starGeometry.vertices.push(vertex);
    }

    var stars = new THREE.Points(starGeometry,new THREE.PointsMaterial({color:0x888888}));
    scene.add(stars);

    var ambientLight = new THREE.AmbientLight( 0x404040 );
    scene.add( ambientLight );

    var pointlight = new THREE.PointLight( 0xffffff, 1, 0, 1);
    pointlight.position.set( 500, 100, 500 );
    //scene.add( pointlight );

    var light = new THREE.DirectionalLight( 0xffffff, 1 );
    light.position.set( -70, 200, 150 );
    light.castShadow = true;
    var d = 10;
    light.shadow.camera.left = -d;
    light.shadow.camera.right = d;
    light.shadow.camera.top = d;
    light.shadow.camera.bottom = -d;

    light.shadow.camera.near = 2;
    light.shadow.camera.far = 50;

    light.shadow.mapSize.width = 1024;
    light.shadow.mapSize.height = 1024;

    light.shadow.bias = -0.001;
    scene.add( light );

    createHouseItem(jsonConvert(houseMap.testString));

    //scene.add(createShape());
    //console.log("init ok"+houseMap.testString);
}

function createHouseItem(objArray){
    console.log("objarray len:" + objArray.length);
    var color;
    var tmp;
    for(var i=0;i<objArray.length;i++){
        if(objArray[i].type === "Device"){
            var machineTexture = textureLoader.load("qrc:/res/texture/machine.jpg");
            machineTexture.wrapS = machineTexture.wrapT = THREE.RepeatWrapping;
            machineTexture.repeat.set(40,40);
            machineTexture.anisotropy = 16;
            var machineGeometry = new THREE.BoxGeometry(Math.abs(objArray[i].positionTLX-objArray[i].positionBRX),
                                                         20,
                                                         Math.abs(objArray[i].positionTLY-objArray[i].positionBRY),
                                                         1,1,1);
            var machineMaterial = new THREE.MeshPhongMaterial({map:machineTexture});
            tmp = new THREE.Mesh(machineGeometry,machineMaterial);
            tmp.position.x = (objArray[i].positionTLX+objArray[i].positionBRX)/2
            tmp.position.y = 0;
            tmp.position.z = (objArray[i].positionTLY+objArray[i].positionBRY)/2
            scene.add(tmp);
        }else if(objArray[i].type === "Door"){
            color = new THREE.Color(0xC07000);
            var doorMaterial = new THREE.MeshLambertMaterial({
                color:color,
                emissive:color
            });
            var doorGeometry = new THREE.BoxGeometry(Math.abs(objArray[i].positionStartX-objArray[i].positionEndX),
                                                         40,
                                                         Math.abs(objArray[i].positionStartY-objArray[i].positionEndY),
                                                         1,1,1);
            tmp = new THREE.Mesh(doorGeometry,doorMaterial);
            tmp.position.x = (objArray[i].positionStartX+objArray[i].positionEndX)/2
            tmp.position.y = 0;//objArray[i].windowBottomHeight;
            tmp.position.z = (objArray[i].positionStartY+objArray[i].positionEndY)/2
            scene.add(tmp);
        }else if(objArray[i].type === "Wall"){
            color = new THREE.Color(0x663300);
            var wallMaterial2 = new THREE.MeshLambertMaterial({
                                                                  color:color,
                                                                  emissive:color
                                                              });
            var wallTexture = textureLoader.load("qrc:/res/texture/wall.jpg");
            wallTexture.wrapS = wallTexture.wrapT = THREE.RepeatWrapping;
            wallTexture.repeat.set(40,40);
            wallTexture.anisotropy = 16;
            var wallMaterial = new THREE.MeshPhongMaterial({map:wallTexture});

            var wallGeometry = new THREE.BoxGeometry(Math.abs(objArray[i].positionStartX-objArray[i].positionEndX),
                                                         50,
                                                         Math.abs(objArray[i].positionStartY-objArray[i].positionEndY),
                                                         1,1,1);
            tmp = new THREE.Mesh(wallGeometry,wallMaterial2);
            tmp.position.x = (objArray[i].positionStartX+objArray[i].positionEndX)/2
            tmp.position.y = 0;
            tmp.position.z = (objArray[i].positionStartY+objArray[i].positionEndY)/2
            scene.add(tmp);
        }else if(objArray[i].type === "Window"){
            color = new THREE.Color(0x6699FF);
            var windowMaterial = new THREE.MeshLambertMaterial({
                color:color,
                emissive:color
            });
            var windowGeometry = new THREE.BoxGeometry(Math.abs(objArray[i].positionStartX-objArray[i].positionEndX),
                                                         20,
                                                         Math.abs(objArray[i].positionStartY-objArray[i].positionEndY),
                                                         1,1,1);
            tmp = new THREE.Mesh(windowGeometry,windowMaterial);
            tmp.position.x = (objArray[i].positionStartX+objArray[i].positionEndX)/2
            tmp.position.y = 10;//objArray[i].windowBottomHeight;
            tmp.position.z = (objArray[i].positionStartY+objArray[i].positionEndY)/2
            scene.add(tmp);
        }else if(objArray[i].type === "Floor"){
            var floorTexture = textureLoader.load("qrc:/res/texture/wood-2.jpg");
            floorTexture.wrapS = floorTexture.wrapT = THREE.RepeatWrapping;
            floorTexture.repeat.set(40,40);
            floorTexture.anisotropy = 16;
            var floorMaterial = new THREE.MeshPhongMaterial({map:floorTexture});

            color = new THREE.Color(0xFFFFCC);


            var options = {
                amount: 2,
                bevelThickness: 1,
                bevelSize: 0.5,
                bevelSegments: 3,
                bevelEnabled: true,
                curveSegments: 12,
                steps: 1
            };
            for(var j=0;j<objArray[i].pointNum;j++){
                var shape = new THREE.Shape();
                if(j==0){
                    //shape.moveTo(objArray[i].positionPointX[j],objArray[i].positionPointY[j]);
                    shape.moveTo(objArray[i].points["point"+j].x,objArray[i].points["point"+j].y);
                }else{
                    //shape.lineTo(objArray[i].positionPointX[j],objArray[i].positionPointY[j]);
                    shape.lineTo(objArray[i].points["point"+j].x,objArray[i].points["point"+j].y);
                }
            }
            var ext = new THREE.ExtrudeGeometry(shape,options);
            var floorMaterial2 = new THREE.MeshBasicMaterial( { color: 0xffffcc } );
            tmp = new THREE.Mesh(ext,floorMaterial2);

//            tmp.position.x = objArray[i].points["Point0"].x;
//            tmp.position.y = 0;//objArray[i].windowBottomHeight;
//            tmp.position.z = objArray[i].points["Point0"].y;
            console.log("a floor");
            //scene.add(tmp);
        }else{
            console.log("cant creat mesh");
        }

    }
}

function resizeGL(canvas) {

    camera.aspect = canvas.width / canvas.height;
    camera.updateProjectionMatrix();

    renderer.setPixelRatio(canvas.devicePixelRatio);
    renderer.setSize( canvas.width, canvas.height );

}

function paintGL(canvas) {
    camera.lookAt(scene.position);
    renderer.render( scene, camera );
}
function createShape(){
    var options = {
        amount: 2,
        bevelThickness: 2,
        bevelSize: 0.5,
        bevelSegments: 3,
        bevelEnabled: true,
        curveSegments: 12,
        steps: 1
    };
    obj = createMesh(new THREE.ExtrudeGeometry(drawShape(),options))

    obj.rotation.x = Math.PI/2;
    obj.position.y = 3;

    return obj;
}

function drawShape(){
    var shape = new THREE.Shape();
    shape.moveTo(0,0);
    shape.lineTo(10,0);
    shape.lineTo(10,1);
    shape.lineTo(12,1);
    shape.lineTo(12,5);
    shape.lineTo(8,5);
    shape.lineTo(8,10);
    shape.lineTo(0,10);
    shape.lineTo(0,0);

    var hole = new THREE.Path();
    hole.moveTo(0.2,0.2);
    hole.lineTo(9.8,0.2);
    hole.lineTo(9.8,1.2);
    hole.lineTo(11.8,1.2);
    hole.lineTo(11.8,4.8);
    hole.lineTo(7.8,4.8);
    hole.lineTo(7.8,9.8);
    hole.lineTo(0.2,9.8);
    hole.lineTo(0.2,0.2);

    shape.holes.push(hole);
    return shape;
}

function createMesh(geom){
    var color = new THREE.Color(0xC07000);
    var material = new THREE.MeshLambertMaterial({
        color:color,
        emissive:color
    });
    var mesh = new THREE.Mesh(geom,material);
    return mesh;
}



