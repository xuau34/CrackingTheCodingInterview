/*
Parking lot -
maintain the amount of Parking areas, and the parked areas
maintain tickets => lists<shared_ptr>
getTicket -
  if(there's space to park)
    register the new ticket, and current timestamp under this ticket
    then give out shared_ptr and remove from list
leave( ticket ) -
  if the ticket's bill hasn't been paid, return the ticket => not allowing

bill machine -
  policy
  bill( ticket ) -
    using this ticket's data to calculate the bill
  pay( ticket, money ) - 
    if not enough, return the money back;
    o.w. modify the ticket's stored timestamp into current one
 */
