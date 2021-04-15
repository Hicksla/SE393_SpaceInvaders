const net = require('net');
const SERVER_PORT = 8006;
const MAX_CONNECTIONS = 12;

class Game {
    constructor(socket, roomStr) {
        this.socket = socket;
        this.roomStr = roomStr;
        
    }

    
}

var games = {
    waitingList:[],
};

const server = net.createServer(function(_socket) {
    // new client connection
    _socket.info = `${_socket.remoteAddress}:${_socket.remotePort} `;
    _socket.gameString = 'waitingList';
    console.log(`${_socket.info}> joined`);
    games[_socket.gameString].push(_socket);

    // server recieves data
    _socket.on('data', function(req_data) {
        data = req_data.toString().split('_');
        switch(data[0]) {
            case 'connect':
                var oldGameString = _socket.gameString;
                _socket.gameString = data[1];
                console.log(`${_socket.info}> ${req_data}`);
                if (games[_socket.gameString] == undefined) {
                    if (games['waitingList'].includes(_socket)) {
                        games['waitingList'].splice(games['waitingList'].indexOf(_socket),1);
                    }
                    
                    games[_socket.gameString] = [_socket];
                    console.log(`${_socket.info}> ${oldGameString} -> ${_socket.gameString}`);
                    _socket.connectLevel = 'host';
                    sendData(_socket,'connect_host');
                } else if ((games[_socket.gameString].length == 1 || _socket.gameString=='waitingList') && !games[_socket.gameString].includes(_socket)) {
                    if (games['waitingList'].includes(_socket)) {
                        games['waitingList'].splice(games['waitingList'].indexOf(_socket),1);
                    }
                    games[_socket.gameString].push(_socket);
                    console.log(`${_socket.info}> ${oldGameString} -> ${_socket.gameString}`);
                    _socket.connectLevel = 'join';
                    sendData(_socket,'connect_join');
                } else {
                    _socket.connectLevel = 'fail';
                    sendData(_socket,'connect_fail');
                }
                break;
            case 'l':
                transmitData(_socket, `l_${data[1]}`);
                break;
            case 'r':
                transmitData(_socket, `r_${data[1]}`);
                break;
            case 's':
                transmitData(_socket, `s_${data[1]}_${data[2]}`);
                break;
            case 'a':
                transmitData(_socket, `a_${data[1]}_${data[2]}_${data[3]}`);
                break;
            default:

        }

    });

    // client disconnect
    _socket.on('end', function() {
        endGame(_socket);
    });

    _socket.on('error', function(err) {
        endGame(_socket);
    });
});

server.listen(SERVER_PORT, function() {
    console.log(`Server on port: ${SERVER_PORT}`);
});

function endGame(socket) {
    if (socket.gameString == "waitingList") {
        return;
    }
    console.log(`${socket.info}> disconnect`);
    if (socket.connectLevel == 'host') {
        try {
        sendData(games[socket.gameString][1],'disconnect');
        delete games[socket.gameString];
        } catch (e){}
        
    } else if (socket.connectLevel == 'join') {
        try {
        sendData(games[socket.gameString][0],'disconnect');
        delete games[socket.gameString];
        } catch (e) {}
        
    }
    
}

function sendData(socket, data) {
    if (!socket.destroyed) {
        socket.write(data+'$');
    }
}

function transmitData(_socket, data) {
    games[_socket.gameString].forEach(function(socket) {
        if (!socket.destroyed && socket != _socket) {
            console.log(`sending to: ${socket.info}> ${data}`);
            sendData(socket, data);
        }
    });
}