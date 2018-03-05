#include <iostream>
#include <stdlib.h>
#include "TcpClient.h"
using namespace std;

int main(){
    TcpClient client;
    client.ip = "127.0.0.1";
    client.port = "8888";
    client.send("1111");
    return 0;
}