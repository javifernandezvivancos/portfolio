column tema_padre format A12
SELECT t1.tema_padre, t2.denominacion, count(*) CUANTOS_HIJOS
FROM tema t1, tema t2
WHERE t1.tema_padre=t2.tema
GROUP BY t1.tema_padre, t2.denominacion
/
