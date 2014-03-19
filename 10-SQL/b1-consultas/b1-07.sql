column nombre_del_autor format A16
SELECT la.libro, la.autor nombre_del_autor
FROM libro_autor la
WHERE la.es_principal='S' AND NOT EXISTS(SELECT *
				                 FROM libro_autor la2
				                WHERE la2.autor!=la.autor AND 
					                la.libro=la2.libro AND 
					                la2.es_principal='S')
/
