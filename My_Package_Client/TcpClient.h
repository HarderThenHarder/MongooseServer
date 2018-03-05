//
// Created by parallels on 18-2-28.
//


/*
 * usage: you could set your own ip/port in your main.cpp by:
 * client.ip = XXX.XXX.XXX.XXX
 * client.port = XXXX
 * send("hello world!")
 */


#ifndef MYPACKAGE_TCPCLIENT_H
#define MYPACKAGE_TCPCLIENT_H
#include <iostream>
#include "mongoose.h"
#include <stdlib.h>


class TcpClient {
    public:
        char *ip = "127.0.0.1";         //default IP
        char *port = "8888";            //default PORT

    public:
        static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) ;
        int send(char *message);        // send method

};


#endif //MYPACKAGE_TCPCLIENT_H
