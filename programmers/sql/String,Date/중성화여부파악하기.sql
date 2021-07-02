SELECT ANIMAL_ID, NAME, case
when SEX_UPON_INTAKE not like "%Neutered%" and SEX_UPON_INTAKE not like "%Spayed%"
then "X"
else "O"
end as 중성화 from ANIMAL_INS
order by ANIMAL_ID asc;