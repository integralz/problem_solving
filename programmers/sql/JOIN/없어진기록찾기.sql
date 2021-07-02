SELECT O.ANIMAL_ID, O.NAME from ANIMAL_OUTS as O
left outer join ANIMAL_INS as I on I.ANIMAL_ID = O.ANIMAL_ID
where I.ANIMAL_ID is null;