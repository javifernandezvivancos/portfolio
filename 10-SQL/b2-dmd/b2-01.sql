--EJERCICIO 1

DROP TABLE SOCIO CASCADE CONSTRAINT ;
DROP TABLE TRABAJADOR CASCADE CONSTRAINT;
DROP TABLE PROYECTO CASCADE CONSTRAINT;
DROP TABLE ONG CASCADE CONSTRAINT;
DROP TABLE COLABORACION CASCADE CONSTRAINT;
DROP TABLE PARTICIPACION CASCADE CONSTRAINT;


CREATE TABLE socio (
nif  NUMBER(8) CONSTRAINT PK_SOCIO PRIMARY KEY,
nombre  VARCHAR(15) NOT NULL);


CREATE TABLE ong(
codigo      NUMBER(10) CONSTRAINT PK_ONG PRIMARY KEY,
nombre      VARCHAR(15) NOT NULL,
direccion   VARCHAR(20) NOT NULL,
telefono    NUMBER(9) NOT NULL,
provincia   VARCHAR(10) NOT NULL,
campo     VARCHAR(30),
responsable NUMBER(8) NOT NULL, 
UNIQUE (RESPONSABLE));


CREATE TABLE colaboracion (
ong       NUMBER(10),
socio     NUMBER(8),
fechaalta DATE,
cuota     NUMBER(7,2),
CONSTRAINT PK_COLABORACION PRIMARY KEY (ONG,socio), 
CONSTRAINT FK_COLABORACION_ONG FOREIGN KEY (ONG) REFERENCES ONG(CODIGO),
CONSTRAINT FK_COLABORACION_SOCIO FOREIGN KEY (SOCIO) REFERENCES SOCIO(NIF));

CREATE TABLE trabajador(
nif NUMBER(8) CONSTRAINT PK_TRABAJADOR PRIMARY KEY,
nombre VARCHAR(20) NOT NULL,
ong NUMBER(10) NOT NULL,
fechaingreso DATE ,
es_voluntario CHAR(1) CHECK(es_voluntario IN('S', 'N')),
nacimiento DATE ,
profesion VARCHAR(15) NULL,
horas NUMBER(4,0) default '0' ,
sueldo NUMBER(7,2),
CONSTRAINT CK_TRABAJADOR CHECK ((es_voluntario IN 'S' AND sueldo=0) OR (es_voluntario IN 'N' and sueldo<>0))); 


CREATE TABLE proyecto(
ong   NUMBER(10) ,
idproyecto NUMBER(3),
objetivo VARCHAR(40) NOT NULL,
pais VARCHAR(20) NOT NULL, 
zona VARCHAR(20) NOT NULL,
numbeneficiarios NUMBER(6,0),
CONSTRAINT PK_PROYECTO PRIMARY KEY (ong,idproyecto));


CREATE TABLE participacion(
ong         NUMBER(10),
proyecto    NUMBER(3),
trabajador  NUMBER(8),
CONSTRAINT PK_PARTICIP PRIMARY KEY (ong,proyecto,trabajador),
CONSTRAINT FK_PARTICIPACION_ONG FOREIGN KEY(ONG) REFERENCES ONG(codigo),
CONSTRAINT FK_PARTICIPACION_PROYECTO FOREIGN KEY(ONG,PROYECTO) REFERENCES PROYECTO(ONG,IDPROYECTO),
CONSTRAINT FK_PARTICIPACION_TRABAJADOR FOREIGN KEY (trabajador) REFERENCES trabajador(nif));



--Insertar filas al trabajador
INSERT INTO trabajador (nif,nombre,ong,fechaingreso,es_voluntario,nacimiento,profesion,horas,sueldo)
VALUES(00000001,'trab1',1111111111,to_date('2004/05/20','YYYY/mm/dd'),'N',to_date('1954/03/27','YYYY/mm/dd'),'medico',1200,2000.00);

INSERT INTO trabajador (nif,nombre,ong,fechaingreso,es_voluntario,nacimiento,profesion,horas,sueldo)
VALUES(00000002,'trab2',1111111112,to_date('2002/11/03','YYYY/mm/dd'),'N',to_date('1964/10/20','YYYY/mm/dd'),'abogado',1300,2100.50);

INSERT INTO trabajador (nif,nombre,ong,fechaingreso,es_voluntario,nacimiento,profesion,horas,sueldo)
VALUES(00000003,'trab3',1111111113,to_date('2005/07/02','YYYY/mm/dd'),'N',to_date('1959/11/04','YYYY/mm/dd'),'profesor',2400,1540.00);

INSERT INTO trabajador (nif,nombre,ong,fechaingreso,es_voluntario,nacimiento,profesion,horas,sueldo)
VALUES(00000004,'trab4',1111111113,to_date('2007/02/15','YYYY/mm/dd'),'S',to_date('1985/12/07','YYYY/mm/dd'),'estudiante',160,0.00);

INSERT INTO trabajador (nif,nombre,ong,fechaingreso,es_voluntario,nacimiento,profesion,horas,sueldo)
VALUES(00000005,'trab5',1111111114,to_date('2005/07/05','YYYY/mm/dd'),'S',to_date('1988/11/05','YYYY/mm/dd'),'policia',125,0.00);

INSERT INTO trabajador (nif,nombre,ong,fechaingreso,es_voluntario,nacimiento,profesion,horas,sueldo)
VALUES(00000006,'trab6',1111111111,to_date('2006/12/15','YYYY/mm/dd'),'S',to_date('1966/10/07','YYYY/mm/dd'),'bombero',100,0.00);

INSERT INTO trabajador (nif,nombre,ong,fechaingreso,es_voluntario,nacimiento,profesion,horas,sueldo)
VALUES(00000007,'trab7',1111111115,to_date('2001/12/05','YYYY/mm/dd'),'N',to_date('1976/08/17','YYYY/mm/dd'),'camarero',1625,2900.00);



--Insertar filas ONG:
INSERT INTO ONG (codigo, nombre, direccion, telefono,provincia,campo,responsable)
VALUES(1111111111,'ONG1','ronda levante 3',633333331,'Prov1','discapacidad',00000001);

INSERT INTO ONG (codigo, nombre, direccion, telefono,provincia,campo,responsable)
VALUES(1111111112,'ONG2','ronda norte 5',633333332,'Prov2','inmigracion',00000002);

INSERT INTO ONG (codigo, nombre, direccion, telefono,provincia,campo,responsable)
VALUES(1111111113,'ONG3','gran via 6',633333333,'Prov3','derechos humanos',000000003);

INSERT INTO ONG (codigo, nombre, direccion, telefono,provincia,campo,responsable)
VALUES(1111111114,'ONG4','ronda sur 16',633333334,'Prov4','ayuda urgente',000000007);

INSERT INTO ONG (codigo, nombre, direccion, telefono,provincia,campo,responsable)
VALUES(1111111115,'ONG5','gracia 23',633333335,'Prov5','cooperacion para necesitados',000000005);



--Insertar filas al proyecto:
Insert into proyecto(ong,idproyecto,objetivo,pais,zona,numbeneficiarios)
Values(1111111111,001,'discapacitados','Inglaterra','Manchester',13000);

Insert into proyecto(ong,idproyecto,objetivo,pais,zona,numbeneficiarios)
Values(1111111112,002,'inmigrantes','Espana','Murcia',7000);

Insert into proyecto(ong,idproyecto,objetivo,pais,zona,numbeneficiarios)
Values(1111111113,003,'discapacitados','Espana','Tarragona',12000);

Insert into proyecto(ong,idproyecto,objetivo,pais,zona,numbeneficiarios)
Values(1111111113,004,'pobres','Espana','Cartagena',9000);

Insert into proyecto(ong,idproyecto,objetivo,pais,zona,numbeneficiarios)
Values(1111111115,005,'ayudas para pobres','Espana','Madrid',15000);

Insert into proyecto(ong,idproyecto,objetivo,pais,zona,numbeneficiarios)
Values(1111111112,006,'inmigracion','Espana','Cadiz',16000);

Insert into proyecto(ong,idproyecto,objetivo,pais,zona,numbeneficiarios)
Values(1111111115,007,'trabajo para inmigrantes','Espana','Huelva',19000);


--Insertar filas socio:
INSERT INTO SOCIO (nif,nombre)
VALUES(00000011,'Roberto Montero');

INSERT INTO SOCIO (nif,nombre)
VALUES(00000012,'Anastasia Lopez');

INSERT INTO SOCIO (nif,nombre)
VALUES(00000013,'Gabriela Sainz');

INSERT INTO SOCIO (nif,nombre)
VALUES(00000014,'Laura Fernandez');

INSERT INTO SOCIO (nif,nombre)
VALUES(00000015,'Benito Alonso');

INSERT INTO SOCIO (nif,nombre)
VALUES(00000016,'Raul Moreno');

INSERT INTO SOCIO (nif,nombre)
VALUES(00000017,'Carlos Leon');

INSERT INTO SOCIO (nif,nombre)
VALUES(00000018,'Helena Rubio');

INSERT INTO SOCIO (nif,nombre)
VALUES(00000019,'Mariona Lopez');

INSERT INTO SOCIO (nif,nombre)
VALUES(00000020,'Andres Gomez');


--Insertar filas colaboración:
INSERT INTO colaboracion(ong,socio,fechaalta,cuota)
VALUES(1111111111,00000011,to_date('2003/01/02','YYYY/mm/dd'),12.00);

INSERT INTO colaboracion(ong,socio,fechaalta,cuota)
VALUES(1111111112,00000012,to_date('2002/11/12','YYYY/mm/dd'),14.00);

INSERT INTO colaboracion(ong,socio,fechaalta,cuota)
VALUES(1111111113,00000013,to_date('2004/10/02','YYYY/mm/dd'),24.00);


INSERT INTO colaboracion(ong,socio,fechaalta,cuota)
VALUES(1111111114,00000015,to_date('2005/11/12','YYYY/mm/dd'),47.00);


INSERT INTO colaboracion(ong,socio,fechaalta,cuota)
VALUES(1111111114,00000017,to_date('2002/12/05','YYYY/mm/dd'),55.00);


INSERT INTO colaboracion(ong,socio,fechaalta,cuota)
VALUES(1111111115,00000018,to_date('2003/08/14','YYYY/mm/dd'),88.00);


INSERT INTO colaboracion(ong,socio,fechaalta,cuota)
VALUES(1111111111,00000019,to_date('2005/10/18','YYYY/mm/dd'),58.00);


INSERT INTO colaboracion(ong,socio,fechaalta,cuota)
VALUES(1111111112,00000020,to_date('2004/10/02','YYYY/mm/dd'),74.00);


INSERT INTO colaboracion(ong,socio,fechaalta,cuota)
VALUES(1111111115,00000016,to_date('2005/03/22','YYYY/mm/dd'),95.00);



--Insertar Filas participación:
INSERT INTO PARTICIPACION (ong,proyecto,trabajador)
VALUES(1111111111,001,00000001);

INSERT INTO PARTICIPACION (ong,proyecto,trabajador)
VALUES(1111111112,002,00000002);

INSERT INTO PARTICIPACION (ong,proyecto,trabajador)
VALUES(1111111113,003,00000003);

INSERT INTO PARTICIPACION (ong,proyecto,trabajador)
VALUES(1111111115,005,00000005);

INSERT INTO PARTICIPACION (ong,proyecto,trabajador)
VALUES(1111111115,005,00000006);

INSERT INTO PARTICIPACION (ong,proyecto,trabajador)
VALUES(1111111112,002,00000004);

INSERT INTO PARTICIPACION (ong,proyecto,trabajador)
VALUES(1111111115,007,00000006);


--FK DE TRABAJADOR
ALTER TABLE TRABAJADOR
ADD constraint fk_trabajador_ong FOREIGN KEY(ONG) REFERENCES ong(CODIGO);

ALTER TABLE PROYECTO
ADD CONSTRAINT FK_PROYECTO_ONG FOREIGN KEY(ONG) REFERENCES ONG(CODIGO);

ALTER TABLE ONG
ADD CONSTRAINT FK_ONG_SOCIO FOREIGN KEY(RESPONSABLE) REFERENCES TRABAJADOR(NIF);

-- Crear en la BD los comentarios (COMMENT) de la tabla TRABAJADOR. 

COMMENT ON TABLE TRABAJADOR IS 'INFORMACIÓN DE LOS TRABAJADORES';
COMMENT ON TABLE TRABAJADOR IS 'ATRIBUTOS: NIF, NOMBRE, ONG, FECHAINGRESO, ESVOLUNTARIO, FECHANACIMIENTO, PROFESION, HORAS, SUELDO';

-- Crear en la BD los comentarios (COMMENT) de todas las columnas de la tabla TRABAJADOR. 

SET LINESIZE 300
SET PAGESIZE 1000

COMMENT ON COLUMN TRABAJADOR.NIF IS 'NIF DEL TRABAJADOR';
COMMENT ON COLUMN TRABAJADOR.NOMBRE IS 'NOMBRE DEL TRABAJADOR';
COMMENT ON COLUMN TRABAJADOR.ONG IS 'ONG PARA LA QUE TRABAJA EL TRABAJADOR';
COMMENT ON COLUMN TRABAJADOR.FECHAINGRESO IS 'FECHA EN LA QUE INGRESÓ EL TRABAJADOR EN LA ONG';
COMMENT ON COLUMN TRABAJADOR.ES_VOLUNTARIO IS 'ALMACENA S SI EL TRABAJADOR ES VOLUNTARIO Y N SI NO LO ES';
COMMENT ON COLUMN TRABAJADOR.NACIMIENTO IS 'FECHA DE NACIMIENTO DEL TRABAJADOR';
COMMENT ON COLUMN TRABAJADOR.PROFESION IS 'PROFESION DEL TRABAJADOR';
COMMENT ON COLUMN TRABAJADOR.HORAS IS 'HORAS QUE TRABAJA EL TRABAJADOR';
COMMENT ON COLUMN TRABAJADOR.SUELDO IS 'SUELDO DEL TRABAJADOR';


SELECT *
FROM USER_TAB_COMMENTS
WHERE TABLE_NAME='TRABAJADOR';


SELECT * 
FROM USER_COL_COMMENTS
WHERE TABLE_NAME='TRABAJADOR'
AND COLUMN_NAME='ONG';


SELECT * 
FROM USER_COL_COMMENTS
WHERE TABLE_NAME='TRABAJADOR';


