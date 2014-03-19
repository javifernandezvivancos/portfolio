SELECT r.autor, nvl(ep.cuantos_principal,0) cuantos_principal,nvl(nep.cuantos_no_principal,0) cuantos_no_principal,nvl(ep.cuantos_principal,0)+nvl(nep.cuantos_no_principal,0) CUANTOS_TOTAL
FROM (SELECT la.autor autor,COUNT(*) cuantos_principal
      FROM libro_autor la
      WHERE es_principal='S'
      GROUP BY la.autor) ep,
      (SELECT la.autor autor,COUNT(*) cuantos_no_principal
       FROM libro_autor la
       WHERE es_principal ='N'
       GROUP BY la.autor) nep, autor r 
WHERE r.autor=ep.autor (+) AND r.autor=nep.autor (+)
ORDER BY r.autor
/
