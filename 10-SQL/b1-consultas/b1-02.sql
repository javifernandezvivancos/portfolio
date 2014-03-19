column f_nacimiento format A15
select a.autor, a.f_nacimiento
FROM autor a
WHERE NOT EXISTS(SELECT a2.f_nacimiento
		FROM autor a2
		WHERE a2.f_nacimiento>a.f_nacimiento AND a2.autor!=a.autor)
/
