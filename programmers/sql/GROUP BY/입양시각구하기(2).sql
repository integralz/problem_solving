set @hour := -1;

SELECT (@hour := @hour + 1) as HOUR, (select count (*) from ANIMAL_OUTS where @hour = hour(DATETIME)) as COUNT  from ANIMAL_OUTS
where @hour < 23;