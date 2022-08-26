//Code based on a geeekforgeeks.com page

#include <stdio.h>
#include <stdlib.h>
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
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
    int was_bought;
    struct Date ticket_date;
    struct Ticket* next_ticket;
};

struct Bought_and_Gifted_tickets{
    int bought_tickets;
    int gifted_tickets;
};

/********** Functions **********/
void deleteATicketFromTheScoreboard(int, struct Bought_and_Gifted_tickets*);
void createTicket(struct Ticket**, struct Bought_and_Gifted_tickets*, char[], char[], int, int[]);
void consultTickets(struct Ticket*, struct Bought_and_Gifted_tickets*, int);
void deleteTicket(struct Ticket**, struct Bought_and_Gifted_tickets*, char[]);

int main(int argc, char const *argv[]){
    
    struct Ticket* ticket_list = NULL;
    struct Bought_and_Gifted_tickets amount_of_tickets;
    amount_of_tickets.bought_tickets = 0;
    amount_of_tickets.gifted_tickets = 0;

    //Process of creating, deleting and reading
    createTicket(&ticket_list, &amount_of_tickets, "Hector", "Cosgalla", 1, (int[5]){22,8,22,12,33});
    createTicket(&ticket_list, &amount_of_tickets, "Edgar Antonio", "Cambranes", 1, (int[5]){22,8,22,10,12});
    createTicket(&ticket_list, &amount_of_tickets, "Eduardo", "Santoscoy Rivera", 0, (int[5]){22,8,22,12,33});
    createTicket(&ticket_list, &amount_of_tickets, "Juan Anselmo", "De la cruz", 1, (int[5]){23,8,22,9,12});
    createTicket(&ticket_list, &amount_of_tickets, "Ucan", "Moo May", 0, (int[5]){22,8,22,12,33});
    //consultTickets(ticket_list, 3, 2);
    //consultTickets(ticket_list, 2);
    deleteTicket(&ticket_list, &amount_of_tickets, "De la cruz");
    deleteTicket(&ticket_list, &amount_of_tickets,"Cosgalla");
    createTicket(&ticket_list, &amount_of_tickets, "Itzel del carmen", "Moo Huchin", 0, (int[5]){23,8,22,14,55});
    consultTickets(ticket_list, &amount_of_tickets, 1);

}

void createTicket(struct Ticket** ticket_list, struct Bought_and_Gifted_tickets* amount_tickets, char first_name[], char last_name[], int was_bought, int date[]){
    if (amount_tickets->bought_tickets == 50 || amount_tickets->gifted_tickets == 100)
    {
        printf("NO HAY BOLETOS DISPONIBLES");
    }else{
        struct Ticket* new_ticket = (struct Ticket*)malloc(sizeof(struct Ticket));
        struct Ticket *last_ticket = *ticket_list;

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
        }else{
            while (last_ticket->next_ticket != NULL){
                last_ticket = last_ticket->next_ticket;
            }
            last_ticket->next_ticket = new_ticket;
        }
        if (was_bought == 1){
            amount_tickets->bought_tickets++;
        } else{
            amount_tickets->gifted_tickets++;
        }
    }
    return;
}

void consultTickets(struct Ticket* ticket_list, struct Bought_and_Gifted_tickets* amount_tickets, int option){
    if (option == 1){
        while (ticket_list){
            printf("first name: %s \nlast name: %s \ndate: %d/%d/%d %d:%d \n\n", ticket_list->first_name, ticket_list->last_name, ticket_list->ticket_date.day, ticket_list->ticket_date.month, ticket_list->ticket_date.year, ticket_list->ticket_date.hour, ticket_list->ticket_date.minute);
            ticket_list = ticket_list->next_ticket;
        }
        printf("total bought: %d\n", amount_tickets->bought_tickets);
        printf("total gifted: %d", amount_tickets->gifted_tickets);

    } 
}

void deleteTicket(struct Ticket** ticket_list, struct Bought_and_Gifted_tickets* amount_tickets,char search_term[]){
    struct Ticket *temporal_ticket = *ticket_list;
    struct Ticket *previous_ticket = NULL;

    if (temporal_ticket && (!strcmp(temporal_ticket->first_name,search_term) || !strcmp(temporal_ticket->last_name,search_term))){
        *ticket_list = temporal_ticket->next_ticket;
        deleteATicketFromTheScoreboard(temporal_ticket->was_bought, amount_tickets);
        free(temporal_ticket);
    }else{
        while (temporal_ticket && strcmp(temporal_ticket->first_name,search_term) && strcmp(temporal_ticket->last_name,search_term)) {
            previous_ticket = temporal_ticket;
            temporal_ticket = temporal_ticket->next_ticket;
        }

        deleteATicketFromTheScoreboard(temporal_ticket->was_bought, amount_tickets);

        if (temporal_ticket){
            previous_ticket->next_ticket = temporal_ticket->next_ticket;
            free(temporal_ticket);
        }
    }
    return;
}

void deleteATicketFromTheScoreboard(int was_bought, struct Bought_and_Gifted_tickets* scoreboard){
    if (was_bought){
        scoreboard->bought_tickets--;
    } else{
        scoreboard->gifted_tickets--;
    }
    return;
}