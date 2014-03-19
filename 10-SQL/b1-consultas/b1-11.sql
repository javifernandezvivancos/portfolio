column editorial format A10
SELECT ME.libro libro, ME.editorial editorial, ME.numveces cuantas_veces
FROM (SELECT p.libro libro, p.editorial editorial, count(*) numVeces
      FROM publicacion p
      GROUP BY p.libro, p.editorial) ME
WHERE (SELECT MAX(count(*))
       FROM publicacion p
       GROUP BY p.libro, p.editorial)=ME.numVeces
/
