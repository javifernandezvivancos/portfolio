--Ejercicio 4:
--Controlamos que al modificar el responsable de una ong, éste sea un trabajador contratado de la misma
CREATE OR REPLACE TRIGGER ONG_TRIGGERS
	BEFORE
	INSERT OR UPDATE OF RESPONSABLE ON ONG
	FOR EACH ROW

DECLARE

	CURSOR C_TRAB IS
	SELECT NIF FROM TRABAJADOR
	WHERE NIF=:NEW.RESPONSABLE AND ES_VOLUNTARIO='N';
	NIF_AUX NUMBER(8);
	
BEGIN
	OPEN C_TRAB;
	FETCH C_TRAB INTO NIF_AUX;
	IF(C_TRAB%FOUND) THEN
		DBMS_OUTPUT.PUT_LINE('Actualizacion correcta');
		DBMS_OUTPUT.PUT_LINE(NIF_AUX);
		FETCH C_TRAB INTO NIF_AUX;	
	ELSE
		DBMS_OUTPUT.PUT_LINE('NO SE PUEDE CREAR');
		RAISE_APPLICATION_ERROR(-20011,'El responsable introducido no es un trabajador contratado de la ong');
	END IF;
END;
/

--Controlamos que al modificar la ONG de un trabajdor, éste no sea el responsable de la que tenía.
CREATE OR REPLACE TRIGGER TRABAJADOR_TRIGGERS
	BEFORE
	INSERT OR UPDATE OF ONG ON TRABAJADOR
	FOR EACH ROW

DECLARE

	CURSOR C_ONG IS
	SELECT RESPONSABLE FROM ONG
	WHERE RESPONSABLE=:NEW.NIF;
	NIF_AUX NUMBER(8);
	
BEGIN
	OPEN C_ONG;
	FETCH C_ONG INTO NIF_AUX;
	IF(C_ONG%FOUND) THEN
		DBMS_OUTPUT.PUT_LINE('NO SE PUEDE CREAR');
		RAISE_APPLICATION_ERROR(-20011,'El trabajador que se intenta modificar es responsable de una ONG');
	ELSE
		DBMS_OUTPUT.PUT_LINE('Actualizacion correcta');
		DBMS_OUTPUT.PUT_LINE(NIF_AUX);
	END IF;
END;
/