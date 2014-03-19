column fecha_ultima_publicacion format A26
SELECT l.libro, l.titulo, nvl(P.cuantas_veces, 0) CUANTAS_VECES, P.fecha_ultima_publicacion
FROM (SELECT p.libro libro, count(*) cuantas_veces, MAX(p.f_publicacion) fecha_ultima_publicacion
	FROM publicacion p
	GROUP BY p.libro) P, libro l
WHERE l.libro = P.libro(+)
/
