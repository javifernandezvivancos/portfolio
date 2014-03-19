column editorial format A10
SELECT e.editorial
FROM editorial e
WHERE e.editorial NOT IN(
	SELECT p.editorial
	FROM publicacion p 
	WHERE p.libro IN(SELECT DISTINCT(LA.libro)
			FROM libro_autor LA
			WHERE LA.es_principal='S' AND LA.autor IN (SELECT DISTINCT ar.autor
	 					FROM articulo ar)))
/
