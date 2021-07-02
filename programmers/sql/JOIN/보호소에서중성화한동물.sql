SELECT O.ANIMAL_ID, O.ANIMAL_TYPE, O.NAME from ANIMAL_OUTS as O
join ANIMAL_INS as I
where I.ANIMAL_ID = O.ANIMAL_ID and ((I.SEX_UPON_INTAKE = "Intact Male" or I.SEX_UPON_INTAKE = "Intact Female") and (O.SEX_UPON_OUTCOME != "Intact Male" and O.SEX_UPON_OUTCOME != "Intact Female"))
order by O.ANIMAL_ID;