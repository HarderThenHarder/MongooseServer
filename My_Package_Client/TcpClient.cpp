//
// Created by parallels on 18-2-28.
//

#include "TcpClient.h"

void TcpClient::ev_handler(struct mg_connection *nc, int ev, void *ev_data){
    switch (ev) {
        case MG_EV_SEND:
            fprintf(stderr, "Send Success!");
            break;
        default:
            break;
    }
    (void) ev_data;
}


int TcpClient::send(char *message) {
    struct mg_mgr mgr;
    char addr[32];
    char ch[5] = ":";
    char mode[10] = "tcp://";

    mg_mgr_init(&mgr, NULL);    //initialize the msr

    sprintf(addr, "%s%s%s%s", mode, ip, ch, port);
    //printf("%s", addr);

    struct mg_connection *nc = mg_connect(&mgr, addr, ev_handler);   //client_function: mg_connect()
    if (nc == NULL) {
    printf("Can't connect to the server!");
    return 1;
    }

    mg_send(nc, message, strlen(message));
    mg_mgr_free(&mgr);
    return 0;
}



