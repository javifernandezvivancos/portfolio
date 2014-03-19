SELECT t.tema, t.denominacion
FROM tema t JOIN articulo r ON r.tema=t.tema
            JOIN libro l ON l.tema=t.tema
WHERE l.f_creacion>=sysdate-5*365 OR r.f_creacion>=sysdate-5*365
/
