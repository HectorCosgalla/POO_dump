package main

import (
	"time"
)

type Date struct {
	day    int
	month  int
	year   int
	hour   int
	minute int
}

type Ticket struct {
	first_name  string
	middle_name string
	last_name   string
	ticket_date Date
	next_ticket *Ticket
}

type bought_tickets struct {
	first_name   string
	middle_name  string
	last_name    string
	point_ticket *Ticket
	next_ticket  *bought_tickets
}

type gifted_tickets struct {
	first_name   string
	middle_name  string
	last_name    string
	point_ticket *Ticket
	next_ticket  *gifted_tickets
}

func (new_ticket Ticket) createATicket(ticket_list *Ticket, first_name, middle_name, last_name string, was_bought bool) {
	//last_ticket := ticket_list
	new_ticket.first_name = first_name
	new_ticket.middle_name = middle_name
	new_ticket.last_name = last_name
	new_ticket.ticket_date.day = int(time.Now().Day())
	new_ticket.ticket_date.month = int(time.Now().Month())
	new_ticket.ticket_date.year = int(time.Now().Year())
	new_ticket.ticket_date.hour = int(time.Now().Hour())
	new_ticket.ticket_date.minute = int(time.Now().Minute())
	new_ticket.next_ticket = nil

	if ticket_list.first_name == "" {
		//ticket_list := new_ticket
		println("Sientro")
	} else {
		println("noentro")
	}
}

func main() {
	tickets := &Ticket{}
	tickets.createATicket(tickets, "Hector", "Abraham", "Cosgalla", true)
	println(tickets.first_name)
}
