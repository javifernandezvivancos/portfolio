column editorial format A10
SELECT E.ed EDITORIAL
FROM (SELECT e.editorial ed,t.tema tem, COUNT(*) num 
	FROM editorial e JOIN publicacion p ON e.editorial=p.editorial
                 JOIN libro l ON l.libro=p.libro
                 JOIN tema t ON l.tema=t.tema
	GROUP BY e.editorial, t.tema) E
GROUP BY E.ed
HAVING COUNT(*)=(SELECT COUNT(*)
        FROM TEMA T
        WHERE TEMA_PADRE IS NULL)
/
