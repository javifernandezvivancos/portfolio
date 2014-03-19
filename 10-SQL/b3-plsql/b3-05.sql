-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--Ejercicio 5:

ALTER TABLE ONG ADD NUM_VOLUNTARIOS NUMBER(2);
ALTER TABLE ONG ADD NUM_CONTRATADOS NUMBER(2);


CREATE OR REPLACE TRIGGER TRIGGER_TRABAJADORES
	AFTER INSERT OR UPDATE OR DELETE 
	ON trabajador
DECLARE

	CURSOR COD_ONG IS
			SELECT CODIGO
			FROM ONG;
    CURSOR voluntarios (xOng number) IS
        		SELECT NIF FROM trabajador WHERE ong=xOng and es_voluntario='S';
    CURSOR contratados (xOng number) IS
            		SELECT NIF FROM trabajador WHERE ong=xOng and es_voluntario='N';
            		
	COD NUMBER(10);
	aux number(10);
	numVoluntarios number(2) := 0;
	numContratados number(2) := 0;
	
BEGIN

	OPEN COD_ONG;
	FETCH COD_ONG INTO COD;
	WHILE (COD_ONG%FOUND) LOOP
			OPEN voluntarios(COD);
			FETCH voluntarios INTO aux;
			WHILE (VOLUNTARIOS%FOUND) LOOP      	            
				numVoluntarios:=numVoluntarios+1;
				FETCH voluntarios INTO aux;
			END LOOP;		
			CLOSE VOLUNTARIOS;
  	        
			UPDATE ONG
			SET NUM_VOLUNTARIOS=numVoluntarios where codigo=cod;
		
			OPEN contratados(COD);
			FETCH contratados INTO aux;
            WHILE (CONTRATADOS%FOUND) LOOP                    
                numContratados:=numContratados+1;
                FETCH contratados INTO aux;
            END LOOP;
            CLOSE CONTRATADOS;
                
			UPDATE ONG
			SET NUM_CONTRATADOS=numContratados where codigo=cod;
		
            numContratados:=0;
            numVoluntarios:=0;
			FETCH COD_ONG INTO COD;

	END LOOP;
	CLOSE COD_ONG;
	
END;
/	