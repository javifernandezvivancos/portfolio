column FECHA_CREACION format A15
SELECT l.libro LIBRO_O_ARTICULO, t.denominacion DENOMINACION_TEMA, l.f_creacion FECHA_CREACION
FROM libro l JOIN tema t ON (l.tema=t.tema)
UNION
SELECT r.articulo, t.denominacion, r.f_creacion
FROM articulo r JOIN tema t ON (r.tema=t.tema)
ORDER BY DENOMINACION_TEMA, FECHA_CREACION
/
