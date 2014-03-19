-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--Ejercicio 3

SET SERVEROUTPUT ON
CREATE OR REPLACE FUNCTION que_es (Xnif IN NUMBER)
return varchar2

IS

I char(30);
sorpresa Exception;
	
BEGIN

	dbms_output.disable;
	dbms_output.enable(1000000);
	dbms_output.put_line(Xnif);
	SELECT SOCIO.nombre INTO I FROM SOCIO, COLABORACION
	WHERE Xnif=SOCIO.nif AND COLABORACION.socio=Xnif;
	
	dbms_output.put_line('C');
	EXCEPTION
		WHEN NO_DATA_FOUND THEN 
			BEGIN
				SELECT SOCIO.nombre INTO I
				FROM SOCIO, COLABORACION				
				WHERE Xnif=SOCIO.nif AND COLABORACION.socio!=Xnif
				group by socio.nombre;
				RETURN('S');
				EXCEPTION
					WHEN NO_DATA_FOUND THEN
						BEGIN
							SELECT TRABAJADOR.nombre INTO I
							FROM TRABAJADOR 
							WHERE Xnif=TRABAJADOR.nif AND TRABAJADOR.es_voluntario='N';
							RETURN ('TC');
							EXCEPTION
								WHEN NO_DATA_FOUND THEN
									BEGIN
										SELECT TRABAJADOR.nombre INTO I
										FROM TRABAJADOR 
										WHERE Xnif=TRABAJADOR.nif AND TRABAJADOR.es_voluntario='S';
										RETURN ('TV');
										EXCEPTION
											WHEN NO_DATA_FOUND THEN
												BEGIN
													RETURN ('E');
												END;
									END;
						END;
							
			END;
		WHEN TOO_MANY_ROWS THEN RETUrn ('C');
		WHEN OTHERS THEN RAISE SORPRESA;	
END;	
/






