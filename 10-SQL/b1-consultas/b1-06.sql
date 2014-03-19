column denominacion_del_tema format A23
column tema_padre format A13
column denominacion_del_tema_padre format A30
SELECT t.tema, t.denominacion denominacion_del_tema, t.tema_padre, l.denominacion denominacion_del_tema_padre
FROM tema t, tema l
WHERE t.tema_padre=l.tema
/
