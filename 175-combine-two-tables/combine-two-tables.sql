# Write your MySQL query statement below

select firstName, lastName,city,state from 
person left join address on  person.personId=address.personId   

-- person, address where person.personId=address.personID  