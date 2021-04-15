
const net = require('net');
const serverPort = 8006;
const MAX_CLIENTS = 12;

// stores active socket connections
var sockets = [];
var ids = [];

const server = net.createServer(function(_socket) {

    // client disconnection
    _socket.on('end', function() {
        removeDeadSockets();
    });

    // server receives data
    _socket.on('data', function(buf) {
        // parse message and determine client
        // console.log(`Message from client: ${buf}`);
        parseMessage(buf);

    });

    _socket.on('error', function() {
        removeDeadSockets();
    });

    getRandomSocketId(MAX_CLIENTS, function(id) {
        
        console.log(`Client connected: ${id}`);
        // send client id
        _socket.write(`${id}$s`);

        // add socket
        sockets.push([_socket,id,false]);
    });
});

function parseMessage(message) {
    var message_data = message.toString().split("_");

    // console.log(`Message from client: ${message}`);
    broadcastMessage(`server response`, message_data[0]);
       
}

server.listen(serverPort, function() {
    console.log(`Server on port: ${serverPort}`);
});


function getRandomSocketId(max, callback) {
    // should check length of sockets (number of connections)

    while (true) { // somewhat dangerous, but with multithreading it's not too bad
        var id = Math.floor(Math.random() * max);
        if (!ids.includes(id)) {
            ids.push(id);
            break;
        }
    }
    return callback(id);
}

function removeDeadSockets() {
    var validSockets = [];

    sockets.forEach(function(socket, index) {
        if (socket[0].destroyed) {

            releaseSocketId(socket[1]);
            console.log(`Client disconnected: ${socket[1]}`);

        }
        else {
            validSockets.push(socket);
        }

        // if we are at the last socket, refresh the socket array
        if (index == sockets.length -1) {
            sockets = validSockets;
        }
    });
}

function releaseSocketId(id) {
    var idIndex = ids.indexOf(id);
    ids.splice(idIndex, 1);
}

function broadcastMessage(message, senderId) {
    // very inefficient, but works for now
    sockets.forEach(function(socket) {
        if (!socket[0].destroyed && socket[1] != senderId) {
            // console.log(`Broadcasting to : ${socket[1]}`);
            socket[0].write(message.toString());
        }
    });
}