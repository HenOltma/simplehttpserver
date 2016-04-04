/* 
 * File:   server.c
 * Author: jannieyk
 *
 * Created on 4. April 2016, 14:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include "filereader.h"

#define SRV_PORT 8998
#define MAX_SOCK 10
#define MAXLINE 512


void dg_echo (int);
void err_abort (char *str);
void exit (int code);
void *memset (void *s, int c, size_t n);
/*
 * 
 */
int mains(int argc, char** argv) {
    // Deskriptoren, Adresslaenge, Prozess-ID
    int sockfd, newsockfd, alen, pid;
    int reuse = 1;
    // Socket Adressen
    struct sockaddr_in cli_addr, srv_addr;
    // TCP-Socket erzeugen
    if((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        err_abort("Kann Stream-Socket nicht oeffnen!");
    }
    // Nur zum Test: Socketoption zum sofortigen Freigeben der Sockets
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) <0){
        err_abort("Kann Socketoption nicht setzen!");
    }
    // Binden der lokalen Adresse damit Clients uns erreichen
    memset((void *)&srv_addr, '\0', sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = htonl (INADDR_ANY);
    srv_addr.sin_port =htons(SRV_PORT);
    if(bind(sockfd, (struct sockaddr *)&srv_addr,
            sizeof(srv_addr)) < 0) {
        err_abort("Kann lokale Adresse nicht binden, laeuft fremder Server?");
    }
    
    // Warteschlange fuer TCP-Socket einrichten
    listen(sockfd,5);
    printf("TCP Echon-Server: bereit ..\n");
    for(;;){
        alen = sizeof(cli_addr);
        // Verbindungsanfrage entgegen nehmen
        newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr, &alen);
        if(newsockfd < 0){
            err_abort("Fehler beim Verbindungsaufbau!");
        }
        //fuer jede Verbindung einen Kindprozess erzeugen
        if (pid = fork()) < 0{
            err_abort("Fehler beim Erzeugen eines Kindprozesses!");
        } else if (pid == 0){
            close (sockfd);
            str_echo (newsockfd);
            exit (0);
        }
        close ( newsockfd);
        }
    }
    return (EXIT_SUCCESS);
}

void err_abort(char *str){
    fprintf(stderr," TCP Echo-Server: %s\n",str);
    fflush(stdout);
    fflush(stderr);
    exit(1);
}

void dg_echo (int sockfd) {
    int alen,n;
    char in[MAXLINE+6], out[MAXLINE+6];
    struct sockaddr_in cli_addr;
    
    for(;;) {
        alen = sizeof (cli_addr);
        memset((void *)&in,'\0',sizeof(in));
        //Daten vom Socket lesen
        n = recvfrom (sockfd, in, MAXLINE, 0,
                (struct sockaddr *)& cli_addr, &alen);
        if(n < 0) {
            err_abort ("Fehler beim Lesen des Sockets!");
        }
        sprintf (out, "Echo: %s", in);

    }
}
