#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#define MAX_NAME 50

/********** Structures **********/
struct Date{
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct Ticket{
    int id;
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
    struct Date ticket_date;
    bool was_bought;
    struct Ticket* next_ticket;
};

/********** Functions **********/
void createTicket(struct Ticket**, char[], char[], bool, int[]);
void deleteTicket();
void printList(struct Ticket*);

int main(int argc, char const *argv[]){
    struct Ticket* ticket_list = NULL;

    createTicket(&ticket_list, "Hector", "Cosgalla", true, (int[5]){22,8,22,12,33});
    createTicket(&ticket_list, "Edgar Antonio", "Cambranes", true, (int[5]){22,8,22,10,12});
    createTicket(&ticket_list, "Eduardo", "Santoscoy Rivera", false, (int[5]){22,8,22,12,33});
    createTicket(&ticket_list, "Juan Anselmo", "De la cruz", true, (int[5]){23,8,22,9,12});
    createTicket(&ticket_list, "Ucan", "Moo May", false, (int[5]){22,8,22,12,33});

    printList(ticket_list);
}

void createTicket(struct Ticket** ticket_list, char first_name[], char last_name[], bool was_bought, int date[]){
    
    struct Ticket* new_ticket = (struct Ticket*)malloc(sizeof(struct Ticket));
    struct Ticket *last_ticket = *ticket_list;

    new_ticket->id = 1;
    strcpy(new_ticket->first_name, first_name);
    strcpy(new_ticket->last_name, last_name);
    new_ticket->was_bought = was_bought;
    new_ticket->ticket_date.day = date[0];
    new_ticket->ticket_date.month = date[1];
    new_ticket->ticket_date.year = date[2];
    new_ticket->ticket_date.hour = date[3];
    new_ticket->ticket_date.minute = date[4];
    new_ticket->next_ticket = NULL;

    if (!*ticket_list){ 
        *ticket_list = new_ticket;
        return;
    }

    
    while (last_ticket->next_ticket != NULL){
        last_ticket = last_ticket->next_ticket;
    }
    
    new_ticket->id += last_ticket->id;
    last_ticket->next_ticket = new_ticket;
    return;
}

void printList(struct Ticket *ticket){
    while (ticket != NULL){
        printf("ticket #%d \nfirst name: %s \nlast name: %s \nwas bought?: %s \ndate: %d/%d/%d %d:%d \n\n", ticket->id, ticket->first_name, ticket->last_name, ticket->was_bought?"yes":"no", ticket->ticket_date.day, ticket->ticket_date.month, ticket->ticket_date.year, ticket->ticket_date.hour, ticket->ticket_date.minute);
        ticket = ticket->next_ticket;
    }
    
}