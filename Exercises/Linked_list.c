#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
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
void consultTickets(struct Ticket*, int, ...);

int main(int argc, char const *argv[]){
    struct Ticket* ticket_list = NULL;

    createTicket(&ticket_list, "Hector", "Cosgalla", true, (int[5]){22,8,22,12,33});
    createTicket(&ticket_list, "Edgar Antonio", "Cambranes", true, (int[5]){22,8,22,10,12});
    createTicket(&ticket_list, "Eduardo", "Santoscoy Rivera", false, (int[5]){22,8,22,12,33});
    createTicket(&ticket_list, "Juan Anselmo", "De la cruz", true, (int[5]){23,8,22,9,12});
    createTicket(&ticket_list, "Ucan", "Moo May", false, (int[5]){22,8,22,12,33});

    consultTickets(ticket_list, 3, 2);
    consultTickets(ticket_list, 2);
    printf("\n\n\n\n\n");
    consultTickets(ticket_list, 1);
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

void consultTickets(struct Ticket* ticket_list, int option, ...){
    if (option == 1){
        
        while (ticket_list != NULL){
            printf("ticket #%d \nfirst name: %s \nlast name: %s \nwas bought?: %s \ndate: %d/%d/%d %d:%d \n\n", ticket_list->id, ticket_list->first_name, ticket_list->last_name, ticket_list->was_bought?"yes":"no", ticket_list->ticket_date.day, ticket_list->ticket_date.month, ticket_list->ticket_date.year, ticket_list->ticket_date.hour, ticket_list->ticket_date.minute);
            ticket_list = ticket_list->next_ticket;
        }

    }else if (option == 2){

        int bought_tickets = 0;
        int gifted_tickets = 0;
        while (ticket_list != NULL){
            if (ticket_list->was_bought){
                bought_tickets++;
            }else{
                gifted_tickets++;
            }
            ticket_list = ticket_list->next_ticket;
        }
        printf("Bought tickets: %d \nGifted tickets: %d", bought_tickets, gifted_tickets);

    }else if (option == 3)
    {
        va_list valist;
        va_start(valist, option);
        ++option;
        while (ticket_list->id != option){
            ticket_list = ticket_list->next_ticket;
        }
        printf("ticket #%d \nfirst name: %s \nlast name: %s \nwas bought?: %s \ndate: %d/%d/%d %d:%d \n\n", ticket_list->id, ticket_list->first_name, ticket_list->last_name, ticket_list->was_bought?"yes":"no", ticket_list->ticket_date.day, ticket_list->ticket_date.month, ticket_list->ticket_date.year, ticket_list->ticket_date.hour, ticket_list->ticket_date.minute);
    }else{
        printf("da fuq ya di bruh!?!?");
    }  
}