SELECT ANIMAL_ID, NAME from ANIMAL_INS
where ANIMAL_TYPE = "Dog" and (NAME like "%El%" or NAME like "%el%")
order by NAME asc;