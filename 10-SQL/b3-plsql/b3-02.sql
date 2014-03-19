---Ejercicio 2

SET SERVEROUTPUT ON 
DECLARE
num_socios NUMBER(2);
num_trab_contratados NUMBER(2);
numero_socio NUMBER (2);
numero_ong NUMBER (2);
numero_trabajadores NUMBER(2);

nombre_ONG VARCHAR2 (20);
nombre_socio VARCHAR2 (20);
nombre_trab_contr_resp VARCHAR2 (20);
nombre_trab_contr_no_resp VARCHAR2 (20);

ESPACIOS CHAR(5);
DOSESPACIOS CHAR(10);

TOT1 CHAR(14);
socio1 CHAR(18);
ong1 CHAR(16);
trabajadores1 CHAR(24);
espacio1 CHAR(2);
nombre VARCHAR2 (20);
ONG_codigo CHAR (10);

CURSOR nom_ONG IS
	SELECT DISTINCT nombre
	FROM ONG;
	
CURSOR datos_socios (ONG_codigo SOCIO.NOMBRE%TYPE) IS
	SELECT DISTINCT SOCIO.nombre
	FROM SOCIO, COLABORACION, ONG
	WHERE COLABORACION.socio = SOCIO.nif AND COLABORACION.ONG = ONG_codigo;
	
CURSOR datos_trab_contratados_resp (ONG_codigo IN CHAR) IS
	SELECT DISTINCT TRABAJADOR.nombre
	FROM TRABAJADOR, ONG
	WHERE ONG_codigo = TRABAJADOR.ONG AND TRABAJADOR.es_voluntario='N' AND ONG.RESPONSABLE=TRABAJADOR.NIF;

CURSOR datos_trab_contratados_no_resp (ONG_codigo IN CHAR) IS
	SELECT DISTINCT TRABAJADOR.nombre
	FROM TRABAJADOR, ONG
	WHERE ONG_codigo = TRABAJADOR.ONG AND TRABAJADOR.es_voluntario='N' AND TRABAJADOR.NOMBRE NOT IN (SELECT DISTINCT TRABAJADOR.nombre
	FROM TRABAJADOR, ONG
	WHERE ONG_codigo = TRABAJADOR.ONG AND TRABAJADOR.es_voluntario='N' AND ONG.RESPONSABLE=TRABAJADOR.NIF);

	
BEGIN

OPEN nom_ONG;

	
TOT1:=('En total hay ');
socio1:=('numero de socios:');
ong1:=('numero de ongs:');
trabajadores1:=('numero de trabajadores:');
ESPACIOS := '-----';
DOSESPACIOS:= '----------';
espacio1:=('  ');
numero_ONG:=0;
numero_socio:=0;
numero_trabajadores:=0;


FETCH nom_ONG INTO nombre_ONG;
WHILE nom_ONG%FOUND
LOOP
	SELECT ONG.codigo INTO ONG_codigo
	FROM ONG
	WHERE ONG.nombre=nombre_ONG;
	numero_ong:=numero_ong+1;
	OPEN datos_socios(ONG_codigo);
	OPEN datos_trab_contratados_resp(ONG_codigo);
	OPEN datos_trab_contratados_no_resp(ONG_codigo);
	
	dbms_output.put_line('ONG: ' ||nombre_ONG);
		
	SELECT COUNT(SOCIO.nombre) INTO num_socios
	FROM SOCIO, COLABORACION, ONG
	WHERE COLABORACION.socio = SOCIO.nif AND COLABORACION.ONG=ONG_CODIGO AND Colaboracion.ong=ONG.codigo;
	
	dbms_output.put_line (ESPACIOS||num_socios||' SOCIOS:');
		
	FETCH datos_socios INTO nombre_socio;
	WHILE datos_socios%FOUND
	LOOP
		dbms_output.put_line(DOSESPACIOS|| nombre_socio);
		numero_socio:=numero_socio+1;
	FETCH datos_socios INTO nombre_socio;
	END LOOP;
	
	SELECT COUNT(TRABAJADOR.nombre) INTO num_trab_contratados
	FROM TRABAJADOR, ONG
	WHERE ONG_codigo = TRABAJADOR.ONG AND TRABAJADOR.es_voluntario='N' AND ONG.CODIGO=TRABAJADOR.ONG;
	
	dbms_output.put_line (ESPACIOS||num_trab_contratados||' TRABAJADORES:');	
	
	
	FETCH datos_trab_contratados_resp INTO nombre_trab_contr_resp;	
	WHILE datos_trab_contratados_resp%FOUND
	LOOP
		dbms_output.put_line(DOSESPACIOS||'RESPONSABLE '||nombre_trab_contr_resp);
	FETCH datos_trab_contratados_resp INTO nombre_trab_contr_resp;	
	numero_trabajadores:=numero_trabajadores+1;
	END LOOP;
	
	FETCH datos_trab_contratados_no_resp INTO nombre_trab_contr_no_resp;	
	WHILE datos_trab_contratados_no_resp%FOUND
	LOOP
		dbms_output.put_line(DOSESPACIOS||'NO RESPONSABLE '||nombre_trab_contr_no_resp);
	FETCH datos_trab_contratados_no_resp INTO nombre_trab_contr_no_resp;
numero_trabajadores:=numero_trabajadores+1;	
	END LOOP;	

	dbms_output.new_line;

	CLOSE datos_socios;
	CLOSE datos_trab_contratados_resp;
	CLOSE datos_trab_contratados_no_resp;
FETCH nom_ONG INTO nombre_ONG;
END LOOP;
		DBMS_OUTPUT.PUT_LINE(TOT1||numero_ong||' ONGs, '||numero_socio||' socios, y '||numero_trabajadores||' trabajadores.');
IF nom_ONG%ISOPEN THEN CLOSE nom_ONG; 
ELSIF datos_socios%ISOPEN THEN CLOSE datos_socios; 
ELSIF datos_trab_contratados_resp%ISOPEN THEN CLOSE datos_trab_contratados_resp;
ELSIF datos_trab_contratados_no_resp%ISOPEN THEN CLOSE datos_trab_contratados_no_resp;
END IF; 		

END;
/