open System

type Tickets =
    struct
    val first_name:string
    val middle_name:string
    val last_name:string
    val date_bought:DateTime
    end

let mutable ticket_list = []
let mutable tickets_bought = []
let mutable tickets_gifted = []


let ticket_list = List.append(ticket_list [3])