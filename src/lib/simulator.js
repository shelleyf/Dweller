Qt.include("/lib/qt-three.js/three.js-master/build/three.js")
Qt.include("/lib/qt-three.js/three.js-master/build/Detector.js")
Qt.include("/lib/qt-three.js/three.js-master/build/OrbitControls.js")

var camera, scene, renderer, mesh, controls, aspect;
var SCREEN_WIDTH, SCREEN_HEIGHT;
var textureLoader;
var clock;

var obj;

function log(message) {
    if (canvas3d.logAllCalls)
        console.log(message)
}

function initializeGL(canvas, eventSource) {
    SCREEN_WIDTH = canvas.width;
    SCREEN_HEIGHT = canvas.height;
    aspect = SCREEN_WIDTH / SCREEN_HEIGHT;

    camera = new THREE.PerspectiveCamera( 50, 0.5 * aspect, 1, 10000 );
    camera.position.x = -31;
    camera.position.y = 50;//18;
    camera.position.z = 30;

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

    var groundGeometry = new THREE.BoxGeometry(40,1,40,1,1,1);
    var groundMaterial = new THREE.MeshPhongMaterial({map:gridTexture});
    var ground = new THREE.Mesh(groundGeometry,groundMaterial);
    ground.position.x = 0;
    ground.position.y = -1;
    ground.position.z = 0;

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

    var light = new THREE.DirectionalLight( 0xffffff, 1 );
    light.position.set( -7, 10, 15 );
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

    scene.add(createShape());
    console.log("init ok");
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



