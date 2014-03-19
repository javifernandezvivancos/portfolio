SELECT t.tema, tem.denominacion, T.numVeces cuantos_articulos
FROM(	SELECT a.tema tema, count(*) numVeces
	FROM articulo a
	GROUP BY a.tema) T, tema tem
WHERE tem.tema=T.tema AND T.numVeces = (SELECT MAX(count(*))
					          FROM articulo a
					          GROUP BY a.tema) 
/
