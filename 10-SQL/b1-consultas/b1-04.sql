SELECT t.tema, t.denominacion
FROM tema t
WHERE NOT EXISTS(SELECT *
	           FROM tema t2	      	
		     WHERE t.tema=t2.tema_padre
		     GROUP BY t2.tema_padre)
/
