
--EJERCICIO 7
--RI1

SELECT T.NIF
FROM PARTICIPACION P, TRABAJADOR T
WHERE T.NIF=P.TRABAJADOR AND P.ONG <>T.ONG;


--RI2
INSERT INTO trabajador (nif,nombre,ong,fechaingreso,es_voluntario,nacimiento,profesion,horas,sueldo)
VALUES(00000013,'trab1',1111111113,to_date('2004/05/20','YYYY/mm/dd'),'N',to_date('1954/03/27','YYYY/mm/dd'),'medico',1200,2000.00);

SELECT T.NIF
FROM TRABAJADOR T,COLABORACION C
WHERE 	T.NIF=C.SOCIO AND 
		T.ONG=C.ONG;


--RI3
	
INSERT INTO trabajador (nif,nombre,ong,fechaingreso,es_voluntario,nacimiento,profesion,horas,sueldo)
VALUES(00000009,'trabX',1111111113,to_date('2010/05/20','YYYY/mm/dd'),'N',to_date('1954/03/27','YYYY/mm/dd'),'medico',1200,2000.00);
	
SELECT NIF 
FROM TRABAJADOR
WHERE FECHAINGRESO > (SELECT SYSDATE FROM DUAL);





--RI4

		SELECT O.codigo,O.responsable
		FROM ONG O
		WHERE O.RESPONSABLE NOT IN (SELECT NIF
									FROM TRABAJADOR T
									WHERE T.NIF=O.RESPONSABLE
											and o.codigo=t.ong);

--RI5
--ALTER TABLE ONG ADD CONSTRAINT RESPONSABLE_1 UNIQUE(RESPONSABLE);
