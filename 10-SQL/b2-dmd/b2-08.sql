--EJERCICIO 8
column index_name format a30;
column table_name format a20;
column column_name format a20;

select index_name,table_name,column_name 
from user_ind_columns
where table_name='TRABAJADOR';

--I1
CREATE INDEX ind_ong
ON TRABAJADOR(ong);

--I2
--No hace falta

--I3 a
CREATE INDEX ind_idproyecto
ON PROYECTO(idproyecto);

--I3 B
--NO HACE FALTA

--I3 C
CREATE INDEX Ind_idproy_obj_pais_zona
ON PROYECTO(idproyecto,objetivo,pais,zona);


select index_name,table_name,column_name 
from user_ind_columns
where table_name='PROYECTO';


