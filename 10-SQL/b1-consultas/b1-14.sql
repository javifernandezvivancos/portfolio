column articulo format A8
SELECT r.articulo
FROM articulo r
WHERE NOT EXISTS(SELECT *
		FROM(	SELECT l.libro l, l.tema t, I.f f
			FROM(	SELECT p.libro l, p.f_publicacion f
				FROM publicacion p
				WHERE NOT EXISTS(SELECT *
						FROM publicacion p2
						WHERE p.libro=p2.libro AND
						p.f_publicacion > p2.f_publicacion)) I, libro l
		WHERE l.libro=I.l) II
		WHERE r.tema = II.t AND r.f_creacion>II.f)
/
