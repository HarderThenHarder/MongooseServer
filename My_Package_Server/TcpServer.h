//
// Created by parallels on 18-2-28.
//

#ifndef MY_PACKAGE_SERVER_TCPSERVER_H
#define MY_PACKAGE_SERVER_TCPSERVER_H

#include "mongoose.h"
#include "server_metheod.h"

class TcpServer {
    public:
       char *port = "8888";     //default port

    public:
        static void ev_handler(struct mg_connection *nc, int ev, void *ev_data){
            struct mbuf *io = &nc->recv_mbuf;
            struct mbuf *sd = &nc->send_mbuf;

            switch (ev) {
                case MG_EV_RECV:
                    when_Receive(io, nc, sd);
                    break;
                case MG_EV_ACCEPT:
                    when_Connect(io, nc);
                    break;
                case MG_EV_SEND:
                    when_Response(io, nc, sd);
                    break;
                case MG_EV_CLOSE:
                    when_Leave(io, nc);
                    break;
                default:
                    break;
            }
        }

            int start() {
            struct mg_mgr mgr;
            mg_mgr_init(&mgr, NULL);  // Initialize event manager object
            mg_bind(&mgr, port, ev_handler);  // Create listening connection
            for (;;) {  // Start infinite event loop
                mg_mgr_poll(&mgr, 1000);
            }
        }
};


#endif //MY_PACKAGE_SERVER_TCPSERVER_H
