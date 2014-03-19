SELECT A.autor AUTOR, A.nombre NOMBRE, nvl(ART1.numAR,0) CUANTOS
FROM (SELECT s.autor, s.nombre nombre
      FROM autor s) A,
     (SELECT ar.autor, COUNT(*) numAr
      FROM articulo ar
      GROUP BY ar.autor) ART1,
      (SELECT la.autor, COUNT(*) numLa
       FROM libro_autor la
       GROUP BY la.autor) LIB1
WHERE A.autor=ART1.autor(+) AND A.autor=LIB1.autor(+) AND nvl(ART1.numAr,0)=nvl(LIB1.numLa,0)

/
