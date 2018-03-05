//
// Created by parallels on 18-2-28.
// 將server各種狀態要採取的各種方法放在這裏
//

#ifndef MY_PACKAGE_SERVER_SERVER_METHEOD_H
#define MY_PACKAGE_SERVER_SERVER_METHEOD_H

#include "stdlib.h"
#include "stdio.h"

void printContent(char *content){
    fprintf(stderr, "%s\n", content);
}


void when_Receive(struct mbuf *io, struct mg_connection *nc, struct mbuf *sd){

    //当服务器接受到客户端请求后动作

    char *recvData = io->buf;   //服務器接受到的data存放在str指針 recvData 中
    int dataSize = io->len;     //接受到 data 的大小
    //your custom code
    // functions available：
    //printContent(char *content)   在終端打印內容
    //mg_send(nc, char *content, int size)  發送消息的方法
    //mbuf_remove(io, io->len)  清空緩存區的方法，每次send完數據後最好調用一次

    printContent(recvData);   // show the receive data
    io->len=0;       // clear the buffer
    mg_send(nc, recvData, dataSize);      // Server send Method
    //end your code
}

void when_Connect(struct mbuf *io, struct mg_connection *nc){

    //当客户端成功连上服务器后的动作
    mbuf_remove(io, io->len);
    printContent("A new client connected!");
}

void when_Response(struct mbuf *io, struct mg_connection *nc, struct mbuf *sd){

    //当服务器成功作出响应，并成功返回数据给客户端时的动作
    sd->len=0;
   // printContent("1 Response Completed!");


}

void when_Leave(struct mbuf *io, struct mg_connection *nc){

    //當客戶端與服務器斷開鏈接時的动作

    printContent("One client left!");
}

#endif //MY_PACKAGE_SERVER_SERVER_METHEOD_H
