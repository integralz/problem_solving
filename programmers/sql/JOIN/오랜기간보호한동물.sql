SELECT I.NAME as NAME, I.DATETIME as DATETIME from ANIMAL_INS as I
left outer join ANIMAL_OUTS as O on I.ANIMAL_ID = O.ANIMAL_ID
where O.ANIMAL_ID is null
order by I.DATETIME asc
limit 3;