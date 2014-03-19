##############################################################################################################################
### Datos ####################################################################################################################
##############################################################################################################################
	.data

tablero: 			.space 1000
tablero_prov: 		.space 1000
tablero_print:		.space 1000
piezas_x:			.byte 2, 2, 2, 2 # X Pieza0
					.byte 3, 2, 3, 2 # X Pieza1
					.byte 3, 2, 3, 2 # X Pieza2
					.byte 2, 3, 2, 3 # X Pieza3
					.byte 2, 3, 2, 3 # X Pieza4
					.byte 3, 2, 3, 2 # X Pieza5
					.byte 1, 4, 1, 4 # X Pieza6
					.byte 2, 4, 2, 4 # X Pieza7
					.byte 2, 4, 2, 4 # X Pieza8
					.byte 3, 2, 3, 2 # X Pieza9
					.byte 3, 3, 3, 3 # X Pieza10
					.byte 3, 3, 3, 3 # X Pieza11
					.byte 3, 3, 3, 3 # X Pieza12
					.byte 2, 2, 2, 2 # X Pieza13
piezas_y: 			.byte 2, 2, 2, 2 # Y Pieza0
					.byte 2, 3, 2, 3 # Y Pieza1
					.byte 2, 3, 2, 3 # Y Pieza2
					.byte 3, 2, 3, 2 # Y Pieza3
					.byte 3, 2, 3, 2 # Y Pieza4
					.byte 2, 3, 2, 3 # Y Pieza5
					.byte 4, 1, 4, 1 # Y Pieza6
					.byte 4, 2, 4, 2 # Y Pieza7
					.byte 4, 2, 4, 2 # Y Pieza8
					.byte 2, 3, 2, 3 # Y Pieza9
					.byte 3, 3, 3, 3 # Y Pieza10
					.byte 3, 3, 3, 3 # Y Pieza11
					.byte 3, 3, 3, 3 # Y Pieza12
					.byte 2, 2, 2, 2 # Y Pieza13
pieza0:				.byte 1, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza0_90:			.byte 1, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza0_180:			.byte 1, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza0_270:			.byte 1, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza1: 			.byte 1, 1, 0, 0
					.byte 0, 1, 1, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza1_90: 			.byte 0, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 1, 0, 0, 0
					.byte 0, 0, 0, 0
pieza1_180: 		.byte 1, 1, 0, 0
					.byte 0, 1, 1, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza1_270: 		.byte 0, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 1, 0, 0, 0
					.byte 0, 0, 0, 0
pieza2: 			.byte 0, 1, 1, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza2_90: 			.byte 1, 0, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
pieza2_180: 		.byte 0, 1, 1, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza2_270: 		.byte 1, 0, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
pieza3: 			.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
pieza3_90: 			.byte 1, 1, 1, 0
					.byte 1, 0, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza3_180: 		.byte 1, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
pieza3_270: 		.byte 0, 0, 1, 0
					.byte 1, 1, 1, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza4: 			.byte 0, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
pieza4_90: 			.byte 1, 0, 0, 0
					.byte 1, 1, 1, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza4_180: 		.byte 1, 1, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 0, 0, 0, 0
pieza4_270: 		.byte 1, 1, 1, 0
					.byte 0, 0, 1, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza5: 			.byte 0, 1, 0, 0
					.byte 1, 1, 1, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza5_90: 			.byte 1, 0, 0, 0
					.byte 1, 1, 0, 0
					.byte 1, 0, 0, 0
					.byte 0, 0, 0, 0
pieza5_180: 		.byte 1, 1, 1, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza5_270: 		.byte 0, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
pieza6: 			.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
pieza6_90: 			.byte 1, 1, 1, 1
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza6_180: 		.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
pieza6_270: 		.byte 1, 1, 1, 1
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
# Piezas añadidas
pieza7: 			.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 1, 0, 0
pieza7_90: 			.byte 1, 1, 1, 1
					.byte 1, 0, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza7_180: 		.byte 1, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 0, 1, 0, 0
pieza7_270: 		.byte 0, 0, 0, 1
					.byte 1, 1, 1, 1
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza8: 			.byte 0, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 1, 1, 0, 0
pieza8_90: 			.byte 1, 0, 0, 0
					.byte 1, 1, 1, 1
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza8_180: 		.byte 1, 1, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
pieza8_270: 		.byte 1, 1, 1, 1
					.byte 0, 0, 0, 1
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza9: 			.byte 1, 0, 1, 0
					.byte 1, 1, 1, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza9_90: 			.byte 1, 1, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
pieza9_180: 		.byte 1, 1, 1, 0
					.byte 1, 0, 1, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza9_270: 		.byte 1, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
pieza10: 			.byte 0, 1, 0, 0
					.byte 1, 1, 1, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
pieza10_90: 		.byte 0, 1, 0, 0
					.byte 1, 1, 1, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
pieza10_180: 		.byte 0, 1, 0, 0
					.byte 1, 1, 1, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
pieza10_270: 		.byte 0, 1, 0, 0
					.byte 1, 1, 1, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
pieza11: 			.byte 1, 1, 1, 0
					.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 0, 0, 0, 0
pieza11_90: 		.byte 1, 1, 1, 0
					.byte 0, 0, 1, 0
					.byte 0, 0, 1, 0
					.byte 0, 0, 0, 0
pieza11_180: 		.byte 0, 0, 1, 0
					.byte 0, 0, 1, 0
					.byte 1, 1, 1, 0
					.byte 0, 0, 0, 0
pieza11_270: 		.byte 1, 0, 0, 0
					.byte 1, 0, 0, 0
					.byte 1, 1, 1, 0
					.byte 0, 0, 0, 0
pieza12: 			.byte 1, 1, 1, 0
					.byte 1, 1, 0, 0
					.byte 1, 0, 0, 0
					.byte 0, 0, 0, 0
pieza12_90: 		.byte 1, 1, 1, 0
					.byte 0, 1, 1, 0
					.byte 0, 0, 1, 0
					.byte 0, 0, 0, 0
pieza12_180: 		.byte 0, 0, 1, 0
					.byte 0, 1, 1, 0
					.byte 1, 1, 1, 0
					.byte 0, 0, 0, 0
pieza12_270: 		.byte 1, 0, 0, 0
					.byte 1, 1, 0, 0
					.byte 1, 1, 1, 0
					.byte 0, 0, 0, 0
pieza13: 			.byte 1, 0, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza13_90: 		.byte 1, 1, 0, 0
					.byte 1, 0, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza13_180: 		.byte 1, 1, 0, 0
					.byte 0, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
pieza13_270: 		.byte 0, 1, 0, 0
					.byte 1, 1, 0, 0
					.byte 0, 0, 0, 0
					.byte 0, 0, 0, 0
num_piezas: 		.byte 14
orden_matriz_pieza:	.byte 4
tam_matriz_pieza: 	.byte 16
mens_op1: 			.asciiz "1. Izquierda / "
mens_op2:			.asciiz "2. Derecha / "
mens_op3: 			.asciiz "3. Abajo\n"
mens_op4:			.asciiz "4. Girar pieza  / "
mens_op5: 			.asciiz "5. Bajar hasta colocar / "
mens_op6: 			.asciiz "7. Fin partida "
mens_op: 			.asciiz "Elija opción: "
mens_op_error: 		.asciiz "La opción no es válida. Elija opción: "
mens_puntuacion:	.asciiz "Puntuación: "
mens_tablero:		.asciiz "Ecriba el tamaño del tablero (tamaño: x*y mínimo=16 / máximo = 1000).\n"
mens_tab_error:		.asciiz "Los datos introducidos no son válidos.\n"
mens_x: 			.asciiz "  -Anchura del tablero: "
mens_y: 			.asciiz "  -Altura del tablero: "
mens_fin: 			.asciiz "¡JUEGO TERMINADO! Su puntuación final: "
mens_espacios3:		.asciiz "   "
cr: 				.asciiz "\n"
celda_impr:         .asciiz "0"
cod_vacio: 			.byte -2
cod_ocupado: 		.byte -3
cod_actual: 		.byte -1	# Pieza en movimiento
car_vacio: 			.byte 46 	# Carácter ASCII de '.'
car_ocupado: 		.byte 127 	# Carácter ASCII (cuadrado negro)
car_actual: 		.byte 88 	# Carácter ASCII de 'X'
car_espacio:		.byte 32 	# Carácter ASCII de ' '
car_sombra:			.byte 94 	# Carácter ASCII de '^'
tam_tablero_x:      .byte 0 	# Tamaño horizontal del tablero
tam_tablero_y:      .byte 0 	# Tamaño vertical del tablero
puntuacion_total:	.word 0
pieza_en_juego:		.byte 0
giro_en_juego:		.byte 0
pieza_siguiente:	.byte 0
pos_pieza_x:		.byte 0
pos_pieza_y:		.byte 0
pos_prov_pieza_x:	.byte 0
pos_prov_pieza_y:	.byte 0
giro_prov_pieza:	.byte 0
##############################################################################################################################
### Programa #################################################################################################################
##############################################################################################################################
	.text 
##############################################################################################################################
# Direccion_celda ############################################################################################################
	# - Entrada: $a0 dirección de la matriz; $a1 fila de la celda; $a2 columna de la celda; $a3 tamaño de la fila de la matriz;
	# - Salida: $v0 dirección de memoria de la celda ($a1, $a2);

Direccion_celda:	mul $t0, $a1, $a3					# Fila * Nº columnas por fila.
					add $t0, $t0, $a2   				# (Fila * Nº columnas por fila) + Columna.
					add $v0, $t0, $a0  					# Pone la dirección calculada en $v0 (Dirección de la matriz + posición dentro de la matriz).
					jr $ra              				# Retorno al código llamante.
##############################################################################################################################
# Obten_celda ################################################################################################################
	# - Entrada: $a0 dirección del tablero; $a1 fila de la celda; $a2 columna de la celda; $a3 tamaño de la fila de la matriz;
	# - Salida: $v0 el valor que contiene la celda ($a1, $a2);

Obten_celda:		subu $sp, $sp, 4					# Reserva espacio en la pila.
					sw $ra, 0($sp)						# Almacena $ra en la pila.					

					jal Direccion_celda					# Llamada a la rutina Direccion_celda.

					lb $t0, 0($v0)						# Pone la direccón de la celda en $t0.
					lb $t1, cod_ocupado					# Pone cod_ocupado en $t1.
					beq $t0, $t1, obten_celda_dato  	# Si la celda contiene el cod_ocupado salta a Obten_celda_dato.
					lb $t1, cod_vacio					# Pone cod_vacio en $t1.
					beq $t0, $t1, obten_celda_dato		# Si la celda contiene el cod_vacio salta a Obten_celda_dato.
					lb $t1, cod_actual					# Pone cod_actual en $t1.
					beq $t0, $t1, obten_celda_dato		# Si la celda contiene el cod_actual salta a Obten_celda_dato.
					addi $t1, $zero, 1					# Pone un 1 en $t1.
					beq $t0, $t1, obten_celda_dato		# Si la celda contiene el un cero salta a Obten_celda_dato
					move $t1, $zero						# Pone un 0 en $t1.
obten_celda_dato:	move $v0, $t1						# Pone el valor de la celda en $v0.

					lw $ra, 0($sp)						# Extrae $ra de la pila.					
					addi $sp, $sp, 4					# Libera espacio reservado en la pila.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Cambia_celda ###############################################################################################################
	# - Entrada: $a0 dirección del tablero; $a1 fila de la celda; $a2 columna de la celda; $a3 valor a poner en la celda
	# - Salida: - (Sin parámetros de salida)

Cambia_celda:		subu $sp, $sp, 8					# Reserva espacio en la pila.
					sw $ra, 4($sp)						# Almacena $ra en la pila.
					sw $s0, 0($sp)						# Almacena $s2 en la pila.

					add $s0, $zero, $a3					# Pone el valor de $a3 en s0.

					lb $a3, tam_tablero_x				# Pone el tamaño de la fila del tablero en $a3.
					jal Direccion_celda					# Llamada a la rutina Direccion_celda.

					sb $s0, 0($v0)						# Cambia la celda con el nuevo valor.

					lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $ra, 4($sp)						# Extrae $ra de la pila.					
					addi $sp, $sp, 8					# Libera espacio reservado en la pila.

					jr $ra         			 			# Retorno al código llamante.
##############################################################################################################################
# Imprime_tablero ############################################################################################################
	# - Entrada: $a0 dirección del tablero; $a1 tamaño de la fila; $a2 altura del tablero;
	# - Salida: - (Sin parámetros de salida)

Imprime_tablero:	subu $sp, $sp, 28					# Reserva espacio en la pila.
					sw $ra, 24($sp)						# Almacena $ra en la pila.
					sw $s5, 20($sp)						# Almacena $s5 en la pila.
					sw $s4, 16($sp)						# Almacena $s4 en la pila.
					sw $s3, 12($sp)						# Almacena $s3 en la pila.
					sw $s2, 8($sp)						# Almacena $s2 en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.					
					sw $s0, 0($sp)						# Almacena $s0 en la pila.

					add $s0, $zero, $a0					# Pone la dirección del tablero en $s0.
					move $s1, $zero						# Inicia iterador (fila) a 0.
					add $s2, $zero, $a1					# Pone el tamaño de la fila en $s2.
					add $s3, $zero, $a2					# Pone la altura del tablero en $s3.

					lb $a0, pieza_siguiente				# Carga el nº de la pieza siguiente.	
					move $a1, $zero						# Pone 0 en $a1.
					jal Direccion_pieza					# Llamada a la rutina Direccion_pieza.

					add $s4, $zero, $v0					# Pone la dirección de memoria de la pieza siguiente en $s4.
					lb $s5, orden_matriz_pieza			# Pone el orden de la matriz de las piezas en $s5.

					la $a0, mens_puntuacion				# Pone la dirección de la cadena mens_puntuacion en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.	
					lw $a0, puntuacion_total			# Pone la puntuacion total en $a0.
					jal Impr_int						# Llamada a la rutina Impr_int.
					la $a0, cr							# Pone la dirección de la cadena cr en $a0
					jal Impr_string						# Llamada a la rutina Impr_string.

Impr_filas:			add $a0, $zero, $s0					# Pone dirección del tablero en $a0.
					add $a1, $zero, $s1					# Pone la fila en $a1.
					add $a2, $zero, $s2					# Pone el tamaño de la fila en $a2.
					jal Imprime_fila					# Llamada a la rutina Imprime_fila.

					bge $s1, $s5, Impr_continua			# Si iterador (fila) es mayor o igual al tamaño de la matriz de las piezas salta a la etiqueta Impr_continua.
					
					la $a0, mens_espacios3				# Pone la dirección de la cadena mens_espacios3 en $a0.
					jal Impr_string						# Llamada a la rutina jal Impr_string.
					
					add $a0, $zero, $s4					# Pone dirección de la pieza en $a0.
					add $a1, $zero, $s1					# Pone la fila en $a1.
					add $a2, $zero, $s5					# Pone el tamaño de la matriz en $a2.
					jal Imprime_fila					# Llamada a la rutina Imprime_fila.

Impr_continua:		la $a0, cr							# Pone la dirección de la cadena cr en $a0.
					jal Impr_string						# Llamada a la rutina jal Impr_string.

					addi $s1, $s1, 1					# Incrementa iterador (fila) en 1.
					blt $s1, $s3, Impr_filas	 		# Si iterador (fila) es menor a la altura del tablero salta a la etiqueta Impr_filas.

					lb $a0, pieza_en_juego				# Pone el nº de la pieza en juego en $a0.
					lb $a1, giro_en_juego				# Pone el giro de la pieza en juego en $a1.
					jal Direccion_pieza					# Llamada a la rutina Direccion_pieza.

					la $t0, piezas_x					# Pone la dirección del vector piezas_x en $t0.
					add $t0, $t0, $v1					# Pone la posición dentro del vector en $t0.
					lb $a1, 0($t0)						# Pone la anhura de la pieza en $a1.
					lb $a0 pos_pieza_x 					# Pone la posición x de la pieza en $a0 
					jal Imprime_sombra					# Llamada a la rutina Imprime_sombra.

					lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $s2, 8($sp)						# Extrae $s2 de la pila.
					lw $s3, 12($sp)						# Extrae $s3 de la pila.
					lw $s4, 16($sp)						# Extrae $s4 de la pila.
					lw $s5, 20($sp)						# Extrae $s5 de la pila.
					lw $ra, 24($sp)						# Extrae $ra de la pila.					
					addi $sp, $sp, 28					# Libera espacio reservado en la pila.	
					
					jr $ra             			 		# Retorno al código llamante
##############################################################################################################################
# Imprime_fila ###############################################################################################################
	# - Entrada: $a0 dirección del tablero; $a1 fila; $a2 tamaño de la fila
	# - Salida: - (Sin parámetros de salida)

Imprime_fila:		subu $sp, $sp, 20					# Reserva espacio en la pila.
					sw $ra, 16($sp)						# Almacena $ra en la pila.
					sw $s3, 12($sp)						# Almacena $s3 en la pila.
					sw $s2, 8($sp)						# Almacena $s2 en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.					
					sw $s0, 0($sp)						# Almacena $s0 en la pila.

					add $s0, $zero, $a0					# Pone la dirección del tablero en $s0.
					add $s1, $zero, $a1					# Pone la fila en $a1.
					move $s2, $zero						# Inicia iterador (columna) a 0.
					add $s3, $zero, $a2					# Pone el tamaño de la fila en $s3.

Impr_celdas:		add $a0, $zero, $s0					# Pone la dirección del tablero en $a0
					add $a1, $zero, $s1					# Pone la fila en $a1.
					add $a2, $zero, $s2					# Pone la columna en $a2.
					add $a3, $zero, $s3					# Pone el tamaño de la fila en $a3.
					jal Obten_celda						# Llamada a la rutina Obten_celta.

					lb $t0, cod_vacio					# Pone cod_vacio en $t0.
					beq $v0, $t0, Impr_car_vacio		# Si la celda contiene cod_vacio salta a la etiqueta Impr_car_vacio.
					lb $t0, cod_ocupado					# Pone cod_ocupado en $t0.
					beq $v0, $t0, Impr_car_ocupado		# Si la celda contiene cod_ocupado salta a la etiqueta Impr_car_ocupado.
					lb $t0, cod_actual					# Pone cod_actual en $t0.
					beq $v0, $t0, Impr_car_actual		# Si la celda contiene cod_actual salta a la etiqueta Impr_car_actual.
					addi $t0, $zero, 1					# Pone un 1 en $t0.
					beq $v0, $t0, Impr_car_actual		# Si la celda contiene un 1 salta a la etiqueta Impr_car_actual.
					move $t0, $zero						# Pone un 0 en $t0.
					beq $v0, $t0, Impr_car_espacio		# Si la celda contiene un 0 salta a la etiqueta Impr_car_espacio.

					j Impr_car_error					# Si no hay coincidencias con ninguna de la anteriores esque hay un error en el tablero y salta a Impr_error.

Impr_car_vacio:		lb $t0, car_vacio					# Pone el código ASCII car_vacio en $t0.
					j Impr_car_celda					# Salto incondicional a Impr_celda.
Impr_car_ocupado:	lb $t0, car_ocupado					# Pone el código ASCII car_ocupado en $t0.
					j Impr_car_celda					# Salto incondicional a Impr_celda.
Impr_car_actual:	lb $t0, car_actual					# Pone el código ASCII car_actual en $t0.
					j Impr_car_celda					# Salto incondicional a Impr_celda.
Impr_car_espacio:	lb $t0, car_espacio					# Pone el código ASCII car_espacio en $t0.
					j Impr_car_celda					# Salto incondicional a Impr_celda.

Impr_car_error:		addi $t0, $zero, 69					# Pone el código ASCII 'E' en $t0.
Impr_car_celda:		sb $t0, celda_impr					# Guarda el Código ASCII a imprimir en la dirección de memoria celda_impr.
					la $a0, celda_impr					# Pone la dirección de la cadena en $a0.
					jal Impr_string						# Llamada la rutina Impr_string.

					addi $s2, $s2, 1					# Incrementa el iterador (columna) en 1. 

					blt $s2, $s3, Impr_celdas	 		# Si iterador (columna) es menor al tamaño de la fila salta a la etiqueta Impr_fila.

					lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $s2, 8($sp)						# Extrae $s2 de la pila.
					lw $s3, 12($sp)						# Extrae $s3 de la pila.
					lw $ra, 16($sp)						# Extrae $ra de la pila.
					addi $sp, $sp, 20					# Libera espacio reservado en la pila.	

					jr $ra             			 		# Retorno al código llamante
##############################################################################################################################
# Mejora: Imprime_sombra ###############################################################################################################
	# - Entrada: $a0 posición x de la pieza; $a1 anchura de la pieza.
	# - Salida: - (Sin parámetros de salida)

Imprime_sombra:		subu $sp, $sp, 16					# Reserva espacio en la pila.
					sw $ra, 12($sp)						# Almacena $ra en la pila.
					sw $s2, 8($sp)						# Almacena $s2 en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.					
					sw $s0, 0($sp)						# Almacena $s0 en la pila.

					add $s0, $zero, $a0					# Pone posición x de la pieza en $s0.
					add $s1, $a0, $a1					# Pone (posición x de la pieza)+(anchura de la pieza) en $s1.
					move $s2, $zero						# Inicia iterador a 0.

Impr_sombra:		blt $s2, $s0, Impr_sombra_espacio	# Si iterador es menor a la posición x de la pieza salta a la etiqueta Impr_sombra_espacio.
					bgt $s2, $s1, Impr_sombra_fin		# Si iterador es mayor a la suma de la posición X y la anchura de la pieza salta a la etiqueta Impr_sombra_fin.

					lb $t0, car_sombra					# Pone  el código ASCII = '^' en $t0.
					sb $t0, celda_impr					# Guarda el Código ASCII a imprimir en la dirección de memoria celda_impr.
					la $a0, celda_impr					# Pone la dirección de la cadena en $a0.
					j Impr_sombra_sig					# Salto incondicional a Impr_sombra_sig.

Impr_sombra_espacio:
					lb $t0, car_espacio					# Carga en $t0 el código ASCII = ' '
					sb $t0, celda_impr					# Guarda el Código ASCII a imprimir en la dirección de memoria celda_impr.
					la $a0, celda_impr					# Pone en $a0 la dirección de la cadena.

Impr_sombra_sig:	jal Impr_string						# Llamada la rutina Impr_string

					addi $s2, $s2, 1					# Incrementa el iterador en 1.
					blt $s2, $s1, Impr_sombra	 		# Si iterador es menor a la suma de la posición X y la anchura de la pieza salta a la etiqueta Impr_sombra

Impr_sombra_fin:	la $a0, cr							# Pone en $a0 la dirección de la cadena.
					jal Impr_string						# Llamada la rutina Impr_string

					lw $s0, 0($sp)						# Extrae $s2 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $s2, 8($sp)						# Extrae $s0 de la pila.
					lw $ra, 12($sp)						# Extrae $ra de la pila.
					addi $sp, $sp,16					# Libera espacio reservado en la pila.	

					jr $ra             			 		# Retorno al código llamante
##############################################################################################################################
# Inicializa_tablero #########################################################################################################
	# - Entrada: $a0 dirección del tablero; $a1 valor con el que inicializar; $a2 tamaño de la fila; $a3 altura del tablero;
	# - Salida: - (Sin parámetros de salida)

Inicializa_tablero:
					subu $sp, $sp, 28					# Reserva espacio en la pila.
					sw $ra, 24($sp)						# Almacena $ra en la pila. 
					sw $s0, 20($sp)						# Almacena $s0 en la pila. 
					sw $s1, 16($sp)						# Almacena $s1 en la pila. 
					sw $s2, 12($sp)						# Almacena $s2 en la pila.
					sw $s3, 8($sp)						# Almacena $s3 en la pila.
					sw $s4, 4($sp)						# Almacena $s4 en la pila.
					sw $s5, 0($sp)						# Almacena $s5 en la pila.

					add $s0, $zero, $a0					# Pone la dirección del tablero en $s0.
					move $s1, $zero  					# Inicia iterador (fila) a 0.
					move $s2, $zero 					# Inicia iterador (columna) a 0.
					add $s3, $zero, $a1					# Pone el valor con el que inicializar en $s3.
					add $s4, $zero, $a2					# Pone el tamaño de la fila en $s4.
					add $s5, $zero, $a3					# Pone la altura del tablero en $s5.

Inic_tabl_celda:	add $a0, $zero, $s0					# Pone la dirección del tablero en $a0.
					add $a1, $zero, $s1					# Pone iterador (fila) en $a1.
					add $a2, $zero, $s2					# Pone iterador (columna) en $a2.
					add $a3, $zero, $s3					# Pone el valor con el que inicializar en $a3.					
					jal Cambia_celda					# Llamada la rutina Cambia_celda.

					addi $s2, $s2, 1					# Incrementa iterador (columna) en 1.
					blt $s2, $s4, Inic_tabl_celda		# Si iterador (columna) es menor al tamañao de la fila salta a la etiqueta Inic_tabl_celda

					move $s2, $zero 					# Reinicia iterador (columna) a 0.
					addi $s1, $s1, 1					# Incrementa iterador (fila) en 1.
					blt $s1, $s5, Inic_tabl_celda		# Si el iterador (fila) es menor que la altura del tablero salta a la etiqueta Inic_tabl_celda

					lw $s5, 0($sp)						# Extrae de la pila $s5.
					lw $s4, 4($sp)						# Extrae de la pila $s4.
					lw $s3, 8($sp)						# Extrae de la pila $s3.
					lw $s2, 12($sp)						# Extrae de la pila $s2.
					lw $s1, 16($sp)						# Extrae de la pila $s1.
					lw $s0, 20($sp)						# Extrae de la pila $s0.
					lw $ra, 24($sp)						# Extrae de la pila $ra.
					addi $sp, $sp, 28					# Libera espacio reservado en la pila.
					
					jr $ra             			   		# Retorno al código llamante
##############################################################################################################################
# Limpiar_fila ###############################################################################################################
	# - Entrada: $a0 dirección del tablero;
	# - Salida: - (Sin parámetros de salida)

Limpiar_fila:		subu $sp, $sp, 20					# Reserva espacio en la pila.
					sw $ra, 16($sp)						# Almacena $ra en la pila.
					sw $s3, 12($sp)						# Almacena $s3 en la pila.	
					sw $s2, 8($sp)						# Almacena $s2 en la pila.	
					sw $s1, 4($sp)						# Almacena $s1 en la pila.					
					sw $s0, 0($sp)						# Almacena $s0 en la pila.

					add $s0, $zero, $a0					# Pone la dirección el tablero en $s0.
					move $s1, $zero						# Inicia iterador (fila) a 0.
					move $s2, $zero						# Inicia contador (filas llenas) a 0.

busca_y_elimina:    add $a0, $zero, $s0					# Pone la dirección del tablero en $a0.
					add $a1, $zero, $s1					# Pone iterador (fila) en $a1.
					lb $a2, tam_tablero_x				# Pone el tamaño de la fila en $a2.
					jal Fila_llena						# Llamada a la rutina Fila_llena.

					blt $v0, $zero no_eliminar_fila		# Si la fila no está llena salta a la etiqueta no_eliminar_fila.

					add $a0, $zero, $s0					# Pone la dirección del tablero en $a0.
					add $a1, $zero, $s1					# Pone la fila completa en $a1.
					jal Limpiar_fila_llena				# Llamada a la rutina Limpiar_fila_llena.

					bne $s2, $zero, no_elimi_fila_uno	# Si contador (filas llenas) es distinto de 0 salta a la etiqueta no_elimi_fila_uno.

					move $s3, $zero						# Inicia iterador (columna) a 0.

elimina_fila_uno:	add $a0, $zero, $s0					# Pone la dirección del tablero en $a0.
					move $a1, $zero						# Pone un 0 en $a1 (primera fila).
					add $a2, $zero, $s3					# Pone iterador (columna) en $a2.
					lb $a3, cod_vacio					# Pone cod_vacio en $a3.
					jal Cambia_celda					# Llamada a la rutina Cambia_celda.
					addi $s3, $s3, 1 					# Incrementa contador (columna) en 1.
					lb $t0, tam_tablero_x  				# Pone el tamaño de la fila en $t0.
					blt $s3, $t0, elimina_fila_uno 		# Si iterador (columna) es menor al tamaño de la .

no_elimi_fila_uno:	addi $s2, $s2, 1					# Incrementa contador (filas llenas) en 1.

no_eliminar_fila:	lb $t0, tam_tablero_y				# Pone la altura del tablero en $t0.
					addi $s1, $s1, 1					# Incrementa iterador (fila) en 1.
					blt $s1, $t0, busca_y_elimina		# Si iterador (fila) es menor a la altura del tablero salta a la etiqueta busca_y_elimina.

					lb $t0, tam_tablero_x				# Pone el tamaño de la fila en $a0 (puntos por limpiar una fila).
					mul $a0, $s2, $t0					# Pone la puntuación por las filas eliminadas en $a1
					jal Act_puntuacion					# Llamada la rutina Act_puntuacion.

					lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $s2, 8($sp)						# Extrae $s2 de la pila.
					lw $s3, 12($sp)						# Extrae $s3 de la pila.
					lw $ra, 16($sp)						# Extrae $ra de la pila.					
					addi $sp, $sp, 20					# Libera espacio reservado en la pila.	

					jr $ra             			 		# Retorno al código llamante
##############################################################################################################################
# Limpiar_fila_llena ########################################################################################################
	# - Entrada: $a0 dirección del tablero; $a1 nº fila llena;
	# - Salida: - (Sin parámetros de salida)

Limpiar_fila_llena:	subu $sp, $sp, 16					# Reserva espacio en la pila.
					sw $ra, 12($sp)						# Almacena $ra en la pila.
					sw $s2, 8($sp)						# Almacena $s2 en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.					
					sw $s0, 0($sp)						# Almacena $s0 en la pila.

					add $s0, $zero, $a0					# Pone la dirección del tablero en $s0.
					add $s1, $zero, $a1 				# Inicia iterador (fila) con el nº de la fila llena.	
					move $s2, $zero						# Inicia iterador (columna) a 0.

copia_celda_sup:	add $a0, $zero, $s0					# Pone la dirección del tablero en $a0
					addi $a1, $s1, -1					# Pone la fila superior en $a1.				
					add $a2, $zero, $s2					# Pone iterador (columna) en $a2.
					lb $a3, tam_tablero_x				# Pone el tamaño de la fila en $a3.
					jal Obten_celda						# Llamada a la rutina Obten_celda.

					add $a0, $zero, $s0					# Pone la dirección del tablero en $a0.
					add $a1, $zero, $s1					# Pone iterador (fila) en $a1.
					add $a2, $zero, $s2					# Pone iterador (columna) en $a2.
					add $a3, $zero, $v0					# Pone el valor de la celda inmediatamente superior en $a3.					
					jal Cambia_celda					# Llamada a la rutina Cambia_celda.

					addi $s2, $s2, 1					# Incrementa iterador (columna) en 1.
					lb $t0, tam_tablero_x				# Pone en $t0  el tamaño de la fila.
					blt $s2, $t0, copia_celda_sup		# Si iterador (columna) es menos al tamaño de la fila salta a la etiqueta copia_celda_sup.

					addi $s1, $s1, -1					# Decrementa iterador (fila) en 1.
					move $s2, $zero						# Reinicia iterador (columna) a 0.
					bgt $s1, $zero, copia_celda_sup		# Si iterador (fila) es mayor que 0 salta a la etiqueta copia_celda_sup.

					lw $s0, 0($sp)						# Extrae $s2 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $s2, 8($sp)						# Extrae $s0 de la pila.
					lw $ra, 12($sp)						# Extrae $ra de la pila.					
					addi $sp, $sp, 16					# Libera espacio reservado en la pila.	

					jr $ra             			 		# Retorno al código llamante
##############################################################################################################################
# Fila_llena #################################################################################################################
	# - Entrada: $a0 dirección del tablero; $a1 nº de la fila; $a2 tamaño de la fila;
	# - Salida: $v0 = 0 si la fila está llena, -1 si no lo está.

Fila_llena: 		subu $sp, $sp, 20					# Reserva espacio en la pila.
					sw $ra, 16($sp)						# Almacena $ra en la pila.
					sw $s3, 12($sp)						# Almacena $s3 en la pila.
					sw $s2, 8($sp)						# Almacena $s2 en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.					
					sw $s0, 0($sp)						# Almacena $s0 en la pila.
					
					add $s0, $zero, $a0					# Pone la dirección del tablero en $s0.
					add $s1, $zero, $a1					# Pone la fila en $s1.
					move $s2, $zero						# Inicia iterador (columna) a 0.
					add $s3, $zero, $a2					# Pone el tamaño de la fila en $s3.

comprueba_celda:	add $a0, $zero, $s0					# Pone la dirección del tablero en $a0.
					add $a1, $zero, $s1					# Pone la fila en $a1.
					add $a2, $zero, $s2					# Pone el iterador (columna) en $a2.
					add $a3, $zero, $s3					# Pone el tamaño de la fila en $a3.
					jal Obten_celda						# Llamada a la rutina Obten_celda.

					lb $t0, cod_ocupado					# Pone cod_ocupado en $t0
					bne $v0, $t0, fila_no_llena			# Si la celda no contine cod_ocupado salta a la etiqueta fila_no_llena.

					addi $s2, $s2, 1					# Incrementa iterador (columna) en 1.
					lb $t0, tam_tablero_x				# Pone el tamaño de la fila en $t0
					blt $s2, $t0, comprueba_celda		# Si iterador (columna) es menor al tamaño de la fila salta a la etiqueta comprueba_celda.

					move $v0, $zero						# Pone un 0 en $v0 (Fila llena por completo).
					j fin_fila_llena					# Salto incondicinal a la etiqueta fin_fila_llena.
fila_no_llena: 		addi $v0, $zero, -1					# Pone un -1 en $v0 (Fila NO llena).

fin_fila_llena:		lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $s2, 8($sp)						# Extrae $s2 de la pila.
					lw $s3, 12($sp)						# Extrae $s3 de la pila.
					lw $ra, 16($sp)						# Extrae $ra de la pila.					
					addi $sp, $sp, 20					# Libera espacio reservado en la pila.	
					
					jr $ra             			 		# Retorno al código llamante
##############################################################################################################################
# Copia_matriz ###############################################################################################################
	# - Entrada: $a0 dirección del tablero a copiar; $a1 dirección del tablero sobre el que hacer la copia;
	# - Salida: - (Sin parámetros de salida)

Copia_matriz:		subu $sp, $sp, 20					# Reserva espacio en la pila.
					sw $ra, 16($sp)						# Almacena $ra en la pila.
					sw $s3, 12($sp)						# Almacena $s3 en la pila.
					sw $s2, 8($sp)						# Almacena $s2 en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.					
					sw $s0, 0($sp)						# Almacena $s0 en la pila.
					
					add $s0, $zero, $a0					# Pone la dirección del tablero a copiar en $s0 .
					add $s1, $zero, $a1					# Pone la dirección del tablero sobre el que hacer la copia en $s1.
					move $s2, $zero						# Inicia iterador (fila) a 0.				
					move $s3, $zero						# Inicia iterador (columna) a 0.
					
copia_celda:		add $a0, $zero, $s0					# Pone dirección del tablero a leer en $a0.
					add $a1, $zero, $s2					# Pone iterador (fila) en $a1.
					add $a2, $zero, $s3					# Pone iterador (columna) en $a2.
					lb $a3, tam_tablero_x				# Pone el tamaño de la fila del tablero en $a3.
					jal Obten_celda						# Llamada a la rutina Obten_celda.

					add $a0, $zero, $s1					# Pone dirección del tablero destino en $a0.
					add $a1, $zero, $s2					# Pone iterador (fila) en $a1.
					add $a2, $zero, $s3					# Pone iterador (columna) en $a2.
					add $a3, $zero, $v0					# Pone el contenido de la celda en $a3.
					jal Cambia_celda					# Llamada a la rutina Cambia_celda.
					
					addi $s3, $s3 1						# Incrementa iterador (columna) en 1.
					lb $t0, tam_tablero_x				# Pone el tamaño de la fila del tablero en $t0
					blt $s3, $t0, copia_celda			# Si iterador (columna) es menor que el tamaño de la fila salta a la etiqueta copia_celda.
					
					addi $s2, $s2, 1					# Incrementa iterador (fila) en 1.
					move $s3, $zero						# Reinicia iterador (columna) a 0
					lb $t0, tam_tablero_y				# Pone la altura del tablero en $t0
					blt $s2, $t0, copia_celda			# Si iterador (fila) es menor que la altura del tablero salta a la etiqueta copia_celda.

					lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $s2, 8($sp)						# Extrae $s2 de la pila.
					lw $s3, 12($sp)						# Extrae $s3 de la pila.
					lw $ra, 16($sp)						# Extrae $ra de la pila.					
					addi $sp, $sp, 20					# Libera espacio reservado en la pila.	

					jr $ra             			 		# Retorno al código llamante
##############################################################################################################################
# Direccion_pieza ############################################################################################################
	# - Entrada: $a0 nº de la pieza; $a1 nº de giro;
	# - Salida: $v0 dirección de memoria de la pieza; $v1 posición dentro del vector del tamaño de la pieza;

Direccion_pieza:	la $t0, pieza0						# Pone la dirección de la primera pieza en $t0.
					lb $t1, tam_matriz_pieza			# Pone el tamaño de la matriz de las piezas en $t1.
					li $t2, 4							# Pone un 4 en $t2 (4 matrices por pieza).
					mul $t3, $t1, $t2					# Pone los bytes que ocupan las cuatro matrices de cada pieza en $t3.
					mul $t3, $a0, $t3					# Multiplica (Nº de la pieza)*(Tamaño de las cuatro matrices por pieza) en $t3.
					add $t0, $t0, $t3					# Pone la direción de la pieza que buscamos (con giro = 0º) en $t0.
					mul $t3, $a1, $t1					# Multiplica el tamaño de la matriz por el nº de giro.
					add $v0, $t0, $t3					# Pone la dirección de la pieza que buscamos con el giro correspondiente en $v0.

					mul $t0, $a0, $t2					# Pone la posición de la pieza dentro del vector (nº pieza * 4 posibles giros) en $t0.
					add $v1, $t0, $a1					# Pone (posición de la pieza dentro del vector)+(nº de giro de la pieza) en $v1.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Coloca_pieza ###############################################################################################################
	# - Entrada: $a0 dirección del tablero; $a1 nº de la pieza; $a2 nº de giro;
	# - Salida: $v0 = 0 si se coloca la pieza correctamente, -1 si no se coloca la pieza;

Coloca_pieza:		subu $sp, $sp, 32					# Reserva espacio en la pila.
					sw $ra, 28($sp)						# Almacena $ra en la pila.
					sw $s6, 24($sp)						# Almacena $s6 en la pila.
					sw $s5, 20($sp)						# Almacena $s5 en la pila.
					sw $s4, 16($sp)						# Almacena $s4 en la pila.
					sw $s3, 12($sp)						# Almacena $s3 en la pila.
					sw $s2, 8($sp)						# Almacena $s2 en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.
					sw $s0, 0($sp)						# Almacena $s0 en la pila.

					add $s0, $zero, $a0					# Pone la dirección del tablero en $s0.

					add $a0, $zero, $a1					# Pone nº de la pieza en $a0.
					add $a1, $zero, $a2					# Pone nº de giro en $a1.
					jal Direccion_pieza					# Llamada a la rutina Direccion_pieza.

					add $s1, $zero, $v0					# Pone dirección de la pieza en $s1.
					add $s2, $zero, $v1					# Pone la posición dentro del vector de los tamaños de la piezas en $s2.
					lb $s3, pos_prov_pieza_y			# Pone la posición (fila) de la pieza $s3.
					lb $s4, pos_prov_pieza_x			# Pone la posición (columna) de la pieza en $s4.
					move $s5, $zero						# Inicia iterador pieza (fila) a 0.
					move $s6, $zero						# Inicia iterador pieza (columna) a 0.

Colocando_fila:		add $a0, $zero, $s1 				# Pone la dirección de la pieza en $a0. 
					add $a1, $zero, $s5 				# Pone el iterador (fila) en $a1.
					add $a2, $zero, $s6 				# Pone el iterador (columna) en $a2.
					lb $a3, orden_matriz_pieza			# Pone el orden de la matriz de las piezas en $a3.
					jal Obten_celda						# Llamada a la rutina Obten_celda.

					beq $v0, $zero, Coloca_celda_sig	# Si la celda es igual a 0 salta a la etiqueta Coloca_celda_sig.

					add $a0, $zero, $s0 				# Pone la dirección del tablero en $a0.
					add $a1, $s3, $s5 					# Pone iterador pieza (fila) en $a1.
					add $a2, $s4, $s6					# Pone iterador pieza (columna) en $a2.
					lb $a3, tam_tablero_x 				# Pone el tamaño de la fila en $a3.
					jal Obten_celda						# Llamada a la rutina Obten_Celda.

					lb $t0, cod_ocupado					# Pone el cod_ocupado en $t0.
					beq $v0, $t0, No_colocada 			# Si la celda contiene cod_ocupado salta a la etiqueta No_colocada.

					add $a0, $zero, $s0					# Pone la dirección del tablero en $a0.
					add $a1, $s3, $s5					# Pone iterador pieza (fila) en $a1.
					add $a2, $s4, $s6					# Pone iterador pieza (columna) en $a2.
					lb $a3, cod_actual					# Pone cod_actual en $a3.				
					jal Cambia_celda					# Llamada a la rutina Cambia_celda.

Coloca_celda_sig:	addi $s6, $s6, 1					# Incrementa el iterador pieza (columna) en 1.

					la $t0, piezas_x					# Pone la dirección del vector piezas_x en $t0
					add $t0, $t0, $s2					# Pone (la dirección del vector + la posición dentro del vector) en $t0.
					lb $t0, 0($t0) 						# Pone el tamaño de la fila de la pieza en $t0.

					blt $s6, $t0, Colocando_fila		# Si el iterador pieza (columna) es menor al tamaño de la pieza salta a la etiqueta Colocando_fila
					
					move $s6, $zero						# Reinicia el iterador pieza (columna) a 0.
					addi $s5, $s5, 1					# Incrementa el iterador pieza (fila) en 1.
					
					la $t0, piezas_y					# Pone la dirección del vector piezas_y en $t0
					add $t0, $t0, $s2					# Pone (direccion del vector) + (posición dentro del vector) en $t0.
					lb $t0, 0($t0) 						# Pone la altura de de la pieza en $t0.
					
					blt $s5, $t0, Colocando_fila		# Si el iterador pieza (fila) es menor a la altura de la pieza salta a la etiqueta Colocando_fila.

					move $v0, $zero						# Pone un 0 en $v0 (Pieza colocada).
					j Coloca_pieza_fin					# Salto incondicional a la etiqueta Coloca_pieza_fin.
No_colocada:		li $v0, -1							# Pone un -1 en $v0 (Pieza sin colocar).

Coloca_pieza_fin:	lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $s2, 8($sp)						# Extrae $s2 de la pila.
					lw $s3, 12($sp)						# Extrae $s3 de la pila.
					lw $s4, 16($sp)						# Extrae $s4 de la pila.
					lw $s5, 20($sp)						# Extrae $s5 de la pila.
					lw $s6, 24($sp)						# Extrae $s6 de la pila.
					lw $ra, 28($sp)						# Extrae $ra de la pila.
					addi $sp, $sp, 32					# Libera espacio reservado en la pila.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Genera_prov ################################################################################################################
	# - Entrada: $a0 dirección tablero; $a1 dirección tablero_prov; $a2 dirección tablero_print;
	# - Salida: $v0 = 0 si tablero_prov se ha generado correctamente, -1 si no se ha generado correctamente;

Genera_prov:		subu $sp, $sp, 16					# Reserva espacio en la pila.
					sw $ra, 12($sp)						# Almacena $ra en la pila.
					sw $s2, 8($sp)						# Almacena $s2 en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.
					sw $s0, 0($sp)						# Almacena $s0 en la pila.

					add $s0, $zero, $a0 				# Pone la dirección de tablero en $s0.
					add $s1, $zero, $a1  				# Pone la dirección de tablero_prov en $s1.
					add $s2, $zero, $a2 				# Pone la dirección tablero_print en $s2. 

					add $a0, $zero, $s0 				# Pone la dirección de tablero en $a0.
					add $a1, $zero, $s1 				# Pone la dirección de tablero_prov en $a1.
					jal Copia_matriz					# Llamada a la rutina Copia_matriz.

					add $a0, $zero, $s1 				# Pone la dirección del tablero_prov en $a0.
					lb $a1, pieza_en_juego  			# Pone el nº de la pieza en juego en $a1.
					lb $a2, giro_prov_pieza				# Pone el nº de giro de la pieza en juego en $a2.
					jal Coloca_pieza					# Llamada a la rutina Coloca_pieza.

					blt $v0, $zero, Genera_prov_inco	# Si la pieza no se colocó correctamente salta a la etiqueta Genera_prov_inco.

					add $a0, $zero, $s1 				# Pone la dirección de tablero_prov en $a0.
					add $a1, $zero, $s2 				# Pone la dirección de tablero_print en $a1.
					jal Copia_matriz					# Llamada a la rutina Copia_matriz.

					lb $t0, pos_prov_pieza_x			# Pone la pos_prov_pieza_x en $t0.
					sb $t0, pos_pieza_x					# Pone pos_prov_pieza_x en la dirección de memoria pos_pieza_x.

					lb $t0, pos_prov_pieza_y			# Pone la pos_prov_pieza_y en $t0.
					sb $t0, pos_pieza_y					# Pone pos_prov_pieza_y en la dirección de memoria pos_pieza_y.
					
					lb $t0, giro_prov_pieza				# Pone el giro_prov_pieza en $t0.
					sb $t0, giro_en_juego				# Pone giro_prov_pieza en la dirección de giro_en_juego.

					move $v0, $zero						# Pone un 0 en $v0 (Se generó correctamente el tablero_prov).
					j Genera_prov_fin					# Salto incondicional a la etiqueta Genera_prov_fin.
Genera_prov_inco:	li $v0, -1							# Pone un -1 en $v0 (NO se generó correctamente tablero_prov).

Genera_prov_fin:	lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $s2, 8($sp)						# Extrae $s2 de la pila.
					lw $ra, 12($sp)						# Extrae $ra de la pila.
					addi $sp, $sp, 16					# Libera espacio reservado en la pila.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Fija_actual ################################################################################################################
	# - Entrada: $a0 dirección del tablero;
	# - Salida: - (Sin parámetros de salida)

Fija_actual:		subu $sp, $sp, 12					# Reserva espacio en la pila.
					sw $ra, 8($sp)						# Almacena $ra en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.
					sw $s0, 0($sp)						# Almacena $s0 en la pila.

					move $s0, $zero						# Inicia iterador (fila) a 0.
					move $s1, $zero						# Inicia iterador (columna) a 0.

F_act_continua:		add $a1, $zero, $s0					# Pone iterador (fila) en $a1.
					add $a2, $zero, $s1					# Pone iterador (columna) en $a2.
					jal Obten_celda						# Llamada a la rutina Obten_celda.	

					lb $t0, cod_actual					# Pone cod_actual en $t0.
					bne $v0, $t0, F_ac_sig				# Si la celda no contiene el cod_actual salta a la etiqueta F_ac_sig.

					lb $a3, cod_ocupado					# Pone cod_ocupado en $a3.
					jal Cambia_celda					# Llamada a la rutina Cambia_celda

F_ac_sig:			addi $s1, $s1, 1					# Incrementa iterador (columna) en 1.
					lb $t0, tam_tablero_x				# Pone el tamaño de la fila en $t0.
					blt $s1, $t0, F_act_continua		# Si iterador (columna) es menor al tamaño de la fila salta a la etiqueta F_act_continua.

					move $s1, $zero						# Reinicia iterador (columna) a 0.
					addi $s0, $s0, 1					# Incrementa iterador (fila) en 1.
					lb $t0, tam_tablero_y				# Pone la altura del tablero en $t0.
					blt $s0, $t0, F_act_continua		# Si iterador (fila) es menor a la altura del tablero salta a la etiqueta F_act_continua.

					lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $ra, 8($sp)						# Extrae $ra de la pila.
					addi $sp, $sp, 12					# Libera espacio reservado en la pila.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Act_nueva_pieza ############################################################################################################
	# - Entrada: $a0 nº de la pieza; $a1 tamaño de la fila del tablero;
	# - Salida:  - (Sin parámetros de salida)

Act_nueva_pieza:	la $t0, pieza_en_juego				# Pone la dirección de memoria de pieza_en_juego.
					sb $a0, 0($t0)						# Guarda el nº de la pieza en la dirección de memoria de pieza_en_juego.

					li $t0, 2							# Pone un 2 en $t0.
					div $t0, $a1, $t0					# Pone la mitad del tamaño de la fila en $t0.
					subu $t0, $t0, 1					# Pone (la mitad del tamaño de la fila) - 1 en $t0.
					sb $t0, pos_pieza_x					# Guarda la posicción inicial X de la pieza en la dirección de memoria pos_pieza_x.
					sb $t0, pos_prov_pieza_x			# Guarda la posicción inicial X de la pieza en la dirección de memoria pos_prov_pieza_x.
					sb $zero, pos_pieza_y				# Guarda la posicción inicial Y de la pieza en la dirección de memoria pos_pieza_y.
					sb $zero, pos_prov_pieza_y			# Guarda la posicción inicial Y de la pieza en la dirección de memoria pos_prov_pieza_y.
					sb $zero, giro_en_juego				# Guarda el giro inicial de la pieza  en la dirección de memoria giro_en_juego.
					sb $zero, giro_prov_pieza			# Guarda el giro inicial de la pieza en la dirección de memoria giro_prov_pieza.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Act_pos_prov ###############################################################################################################
	# - Entrada: $a0 Posición de memoria de $x, $a1 Posición de memoria de $y, $a2 Posición de memoria del giro
	# - Salida: - (Sin parámetros de salida)

Act_pos_prov:		la $t0, pos_prov_pieza_x			# Pone la dirección de memoria pos_prov_pieza_x en $t0.
					lb $t1, 0($a0)						# Pone la posicción X de la pieza en $t1.
					sb $t1, 0($t0)						# Guarda la posicción X de la pieza  en la dirección de memoria pos_prov_pieza_x.
					la $t0, pos_prov_pieza_y			# Pone la dirección de memoria pos_prov_pieza_y en $t0.
					lb $t1, 0($a1)						# Pone la posicción Y de la pieza en $t1.
					sb $t1, 0($t0)						# Guarda la posicción Y de la pieza en la dirección de memoria pos_prov_pieza_y.
					la $t0, giro_prov_pieza				# Pone la dirección de memoria giro_prov_pieza en $t0.
					lb $t1, 0($a2)						# Pone el giro de la pieza en $t1.
					sb $t1, 0($t0)						# Guarda el giro de la pieza en la dirección de memoria giro_prov_pieza.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Configura_tablero ################################################################################################################
	# - Entrada: $a0 anchura del tablero; $a1 altura del tablero;
	# - Salida: $v0 = 0 si el tamaño es posible, -1 si el tamaño no es válido.

Configura_tablero:	subu $sp, $sp, 12					# Reserva espacio en la pila.
					sw $ra, 8($sp)						# Almacena $ra en la pila.
					sw $s1, 4($sp)						# Almacena $s1 en la pila.
					sw $s0, 0($sp)						# Almacena $s0 en la pila.
					
					add $s0, $zero, $a0					# Pone la anchura del tablero en $s0
					add $s1, $zero, $a1					# Pone la altura del tablero en $s1
					
					mul $t0, $s0, $s1					# Pone el tamaño total del tablero del usuario en $t0.
					li $t1, 1000						# Pone el tamaño máximo posible del tablero en $t1.
					bgt $t0, $t1, Config_tab_error  	# Si el tamaño del usuario es mayor del permitido, salta a la etiqueta Config_tab_error.
					li $t1, 16							# Pone el tamaño mínimo posible del tablero en $t1.
					blt $t0, $t1, Config_tab_error  	# Si el tamaño del usuario es mayor del permitido, salta a la etiqueta Config_tab_error.

					sb $s0, tam_tablero_x				# Guarda la anchura del tablero del usuario en tam_tablero_x.
					sb $s1, tam_tablero_y				# Guarda la altura del tablero del usuario en tam_tablero_y.

					move $v0, $zero						# Pone un 0 en $v0 (tamaño válido).
					j Config_tab_fin					# Salto incondicional a la etiqueta Config_tab_fin.

Config_tab_error:	la $a0, mens_tab_error				# Pone la dirección de memoria de mens_tab_error en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					li $v0, -1							# Pone un -1 en $v0 (tamaño NO válido).
					
Config_tab_fin:		lw $s0, 0($sp)						# Extrae $s0 de la pila.
					lw $s1, 4($sp)						# Extrae $s1 de la pila.
					lw $ra, 8($sp)						# Extrae $ra de la pila.
					addi $sp, $sp, 12					# Libera espacio reservado en la pila.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Num_aletorio ###############################################################################################################
	# - Entrada: $a0 Cota superior para el número aleatorio.
	# - Salida: $v0 = Número aleatorio generado.

Num_aleatorio:
					addi $sp, $sp, -4
					sw $ra, 0($sp)
					add $t0, $2, $t0
					add $t0, $3, $t0
					add $t0, $4, $t0
					add $t0, $5, $t0
					add $t0, $6, $t0
					add $t0, $7, $t0
					add $t0, $9, $t0
					add $t0, $10, $t0
					add $t0, $11, $t0
					add $t0, $12, $t0
					add $t0, $13, $t0
					add $t0, $14, $t0
					add $t0, $15, $t0
					add $t0, $16, $t0
					add $t0, $17, $t0
					add $t0, $18, $t0
					add $t0, $19, $t0
					add $t0, $20, $t0
					add $t0, $21, $t0
					add $t0, $22, $t0
					add $t0, $23, $t0
					add $t0, $24, $t0
					add $t0, $25, $t0
					add $t0, $26, $t0
					add $t0, $27, $t0
					add $t0, $28, $t0
					add $t0, $30, $t0
					add $t0, $31, $t0
					divu $t0, $a0
					mfhi $v0
					lw $ra, 0($sp)
					addi $sp, $sp, 4
					jr $ra
##############################################################################################################################
# Imprime_opciones ###########################################################################################################
	# - Entrada:
	# - Salida: (Imprime por consola el menú de opciones)
	#
Imprime_opciones:	subu $sp, $sp, 4					# Reserva espacio en la pila.
					sw $ra, 0($sp)						# Almacena $ra en la pila.

					la $a0, mens_op1 					# Pone la dirección de mens_op1 en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					la $a0, mens_op2 					# Pone la dirección de mens_op2 en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					la $a0, mens_op3 					# Pone la dirección de mens_op3 en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					la $a0, mens_op4 					# Pone la dirección de mens_op4 en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					la $a0, mens_op5 					# Pone la dirección de mens_op5 en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					la $a0, mens_op6 					# Pone la dirección de mens_op5 en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					la $a0, cr 							# Pone la dirección de cr en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					la $a0, mens_op 					# Pone la dirección de mens_op en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.

					lw $ra, 0($sp)						# Extrae $ra de la pila.
					addi $sp, $sp, 4					# Libera espacio reservado en la pila.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Mejora: Puntuación #########################################################################################################
	# - Entrada: $a0 puntos a añadir;
	# - Salida: - (sin parámetros de salida)
	#
Act_puntuacion:		lw $t0, puntuacion_total			# Pone puntacion_total en $t0.
					add $t0, $t0, $a0					# Pone (puntuación total)+(nuevos puntos) en $t0.
					sw $t0, puntuacion_total			# Guarda la nueva puntuacion en la posición de memoria puntacion_total.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Útil: Leer_teclado_int #####################################################################################################
# - Entrada: - (sin parámetros de entrada)
# - Salida: $v0 entero leido desde teclado
#
Leer_teclado_int:	li $v0, 5 							# Número de servicio de llamada al sistema (read int).
					syscall 							# Llamada al sistema que lee un entero.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Útil: Impr_string ##########################################################################################################
	# - Entrada: $a0 dirección del string a imprimir;
	# - Salida: - (sin parámetros de salida)
	#
Impr_string:		li $v0, 4							# Código de llamada al sistema print_string.
					syscall								# Imprimimos string que empieza en la dirección $a0.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# Útil: Impr_int #############################################################################################################
	# - Entrada: $a0 dirección del int a imprimir;
	# - Salida: - (sin parámetros de salida)
	#
Impr_int:			li $v0, 1							# Código de llamada al sistema print_int.
					syscall								# Imprimimos string que empieza en la dirección $a0.

					jr $ra             			    	# Retorno al código llamante.
##############################################################################################################################
# MAIN #######################################################################################################################
main:	

# El usuario elige el tamaño del tablero
Iniciar_nuevo_tab:	la $a0, mens_tablero				# Pone la dirección de memoria de mens_tablero en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					la $a0, mens_x						# Pone la dirección de memoria de mens_x en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					jal Leer_teclado_int				# Llamada a la rutina Leer_teclado_int.
					add $s0, $zero, $v0					# Pone la anchura deseada por el usuario en $s0.

					la $a0, mens_y						# Pone la dirección de memoria de mens_y en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					jal Leer_teclado_int				# Llamada a la rutina Leer_teclado_int.
					add $s1, $zero, $v0					# Pone la anchura deseada por el usuario en $s1.
					
					add $a0, $zero, $s0					# Pone la anchura deseada por el usuario en $a0.
					add $a1, $zero, $s1					# Pone la altura deseada por el usuario en $a1.
					jal Configura_tablero				# Llamada a la rutina Configura_tablero.
					blt $v0, $zero, Iniciar_nuevo_tab	# Si el tamaño no es válido salta a la etiqueta Iniciar_nuevo_tab.

# Genera la matriz tablero con el valor cod_vacio en todas sus posiciones
					la $a0, tablero						# Pone la dirección de memoria de tablero en $a0.
					lb $a1, cod_vacio					# Pone cod_vacio en $a1.
					lb $a2, tam_tablero_x				# Pone el tamaño de la fila en $a2.
					lb $a3, tam_tablero_y				# Pone la altura del tablero en $a3.
					jal Inicializa_tablero				# Llamada a la rutina Inicializa_tablero.

# Asigna los valores x=(columna mitad de la fila) y y=(primera fila) y genera una pieza aleatoria.
					lb $a0, num_piezas					# Pone num_piezas en $a0.
					jal Num_aleatorio					# Llamada a la rutina Num_aleatorio.
					sb $v0, pieza_siguiente				# Guarda el nº de una pieza en la dirección de memoria pieza_siguiente.

jugar_nueva_pieza:	addi $a0, $zero, 1					# Pone la puntuación por nueva pieza jugada en $a0.
					jal Act_puntuacion					# Llamada a la rutina Act_puntuacion.

					lb $a0, pieza_siguiente				# Pone el nº de la siguiente pieza en $a0.
					lb $a1, tam_tablero_x				# Pone la anchura del tablero en $a1.
					jal Act_nueva_pieza					# Llamada a la rutina Act_nueva_pieza.

					lb $a0, num_piezas					# Pone num_piezas en $a0.
					jal Num_aleatorio					# Llamada a la rutina Num_aleatorio.
					sb $v0, pieza_siguiente				# Guarda el nº de una pieza en la dirección de memoria pieza_siguiente.

# Genera la matriz tablero_prov, generándose, automáticamente, la matriz tablero_print
jugando:			la $a0, pos_pieza_x								# Pone la dirección de memoria de pos_pieza_x en $a0.
					la $a1, pos_pieza_y								# Pone la dirección de memoria de pos_pieza_y en $a1.
					la $a2,	giro_en_juego							# Pone la dirección de memoria de giro_en_juego en $a2.
					jal Act_pos_prov								# Llamada a la rutina Act_pos_prov.

					la $a0, tablero						# Pone la dirección de memoria de tablero en $a0.
					la $a1, tablero_prov				# Pone la dirección de memoria de tablero_prov en $a1.
					la $a2, tablero_print				# Pone la dirección de memoria de tablero_print en $a2.
					jal Genera_prov						# Llamada a la rutina Genera_prov.
					lb $t0, pos_pieza_y					# Pone la posicción Y de la pieza en $t0.
					bne $t0, $zero, jugando_cont		# Si la posición de la pieza es la primera fila y...
					blt $v0, $zero, fin_del_juego		# ... y no se genera correctamente el tablero_prov, fin del juego.

# Imprime la matriz tablero_print
jugando_cont:		la $a0, tablero_print				# Pone la dirección de memoria de tablero_print en $a0.
					lb $a1, tam_tablero_x				# Pone el tamaño de la fila en $a1.
					lb $a2, tam_tablero_y				# Pone la altura del tablero en $a2.
					jal Imprime_tablero					# Llamada a la rutina Imprime_tablero.

# Imprime menú de opciones
jugando_opciones: 	jal Imprime_opciones				# Llamada a la rutina Imprime_opciones.
jugando_elegir_op:	jal Leer_teclado_int				# Llamada a la rutina Leer_teclado_int.
					addi $s0, $zero, 1					# Pone el nº 1 en $t1.
					beq $v0, $s0, opcion_izquierda		# Si opción elegida es igual a 1 salta a la etiqueta opcion_izquierda.
					addi $s0, $zero, 2					# Pone el nº 2 en $t1.
					beq $v0, $s0, opcion_derecha		# Si opción elegida es igual a 2 salta a la etiqueta opcion_derecha.
					addi $s0, $zero, 3					# Pone el nº 3 en $t1.
					beq $v0, $s0, opcion_abajo			# Si opción elegida es igual a 3 salta a la etiqueta opcion_abajo.
					addi $s0, $zero, 4					# Pone el nº 4 en $t1.
					beq $v0, $s0, opcion_girar			# Si opción elegida es igual a 4 salta a la etiqueta opcion_girar.
					addi $s0, $zero, 5					# Pone el nº 5 en $t1.
					beq $v0, $s0, opcion_abajo			# Si opción elegida es igual a 5 salta a la etiqueta opcion_bajar_fijar.
					addi $s0, $zero, 7					# Pone el nº 7 en $t1.
					beq $v0, $s0, opcion_salir			# Si opción elegida es igual a 5 salta a la etiqueta opcion_salir.

					la $a0, mens_op_error				# Pone la dirección de memoria de mens_op_error en $a0.
					jal Impr_string						# Llamada a la rutina Impr_string.
					j jugando_elegir_op					# Salto incondicional a la etiqueta main_elegir_opcion.

# SEGÚN opcion_elegida
opcion_izquierda:	# Izquierda: 
						# - Comprueba que la pieza en juego no está en la columna 1 ($x<>1). Si es así:
						lb $t0, pos_pieza_x							# Pone la posición X de la pieza en $t0.
						beq $t0, $zero, opcion_izquierda_fin		# Si la posición X de la pieza es igual a 0 salta a la etiqueta opcion_izquierda_fin.
						# - $xprov = $x -1 y $yprov = $y
						la $a0, pos_pieza_x							# Pone la dirección de memoria de la posición X de la pieza en $a0. 
						la $a1, pos_pieza_y							# Pone la dirección de memoria de la posición Y de la pieza en $a1. 
						la $a2,	giro_en_juego						# Pone la dirección de memoria del giro de la pieza en $a2. 
						jal Act_pos_prov							# Llamada a la rutina Act_pos_prov.
						lb $t0, pos_prov_pieza_x					# Pone pos_prov_pieza_x en $t0.
						subu $t0, $t0, 1							# Decrementa la posición provisional en 1.
						sb $t0, pos_prov_pieza_x					# Guarda la nueva posicción provisional en  la dirección de memoria pos_prov_pieza_x.
						# - Genera la matriz tablero_prov
						la $a0, tablero								# Pone la dirección de memoria de tablero en $a0.
						la $a1, tablero_prov						# Pone la dirección de memoria de tablero_prov en $a1.
						la $a2, tablero_print						# Pone la dirección de memoria de tablero_print en $a2.
						jal Genera_prov								# Llamada a la rutina Genera_prov.
opcion_izquierda_fin:	j jugando									# Salto incondicional a la etiqeuta jugando.

opcion_derecha:		# Derecha: 
						# - Comprueba que la pieza en juego no tendría celdas ocupadas fuera del tablero. ($xprov + piezas_x <= 10). Si es así:
						lb $a0, pieza_en_juego						# Pone la pieza en juego en $a0.
						lb $a1, giro_en_juego						# Pone el giro en juego en $a1.
						jal Direccion_pieza							# Llamada a la rutina Direccion_pieza.
						la $t0, piezas_x							# Pone la dirección de memoria del vector piezas_x en $t0.
						add $t0, $t0, $v1							# Pone (dirección del vector) + (posición dentro del vector) en $t0.
						lb $t0, 0($t0) 								# Pone la anchura de la pieza en $t0.
						lb $t1, pos_pieza_x							# Pone la posición de la pieza en $t1.
						add $t0, $t0, $t1							# Pone (posición de la pieza) + (anchura de la pieza) en $t0.
						lb $t1, tam_tablero_x						# Pone el tamaño de la fila en $t1.
						bge $t0, $t1, opcion_derecha_fin			# Si la pieza se sale del tablero salta a la etiqueta opcion_derecha_fin.
						# - $xprov = $x +1 y $yprov = $y
						la $a0, pos_pieza_x							# Pone la dirección de memoria de pos_pieza_x $a0.
						la $a1, pos_pieza_y							# Pone la dirección de memoria de pos_pieza_y $a1.
						la $a2,	giro_en_juego						# Pone la dirección de memoria de giro_en_juego en $a2.
						jal Act_pos_prov							# Llamada a la rutina Act_pos_prov.
						lb $t0, pos_prov_pieza_x					# Pone la pos_prov_pieza_x en $t0.
						addi $t0, $t0, 1							# Incrementa la posición X provisional en 1.
						sb $t0, pos_prov_pieza_x					# Guarda la nueva posición X provisonal.
						# - Genera la matriz tablero_prov
						la $a0, tablero								# Pone la dirección de memoria de tablero en $a0.
						la $a1, tablero_prov						# Pone la dirección de memoria de tablero_prov en $a1.
						la $a2, tablero_print						# Pone la dirección de memoria de tablero_print en $a2.
						jal Genera_prov								# Llamada a la rutina Genera_prov.
opcion_derecha_fin:		j jugando									# Salto incondicional a la etiqueta jugando.

opcion_abajo:		# Abajo
					# - Si la pieza en juego está en la última fila:
						# - Convierte la pieza en “fija” y comprueba la existencia de filas completas.
						lb $a0, pieza_en_juego						# Pone la pieza en juego en $a0.
						lb $a1, giro_en_juego						# Pone el giro en juego en $a1.
						jal Direccion_pieza							# Llamada a la rutina Direccion_pieza.
						la $t0, piezas_y							# Pone la dirección del vector piezas_y en $t0.
						add $t0, $t0, $v1							# Pone (direccion del vector) + (posición dentro del vector) en $t0.
						lb $t0, 0($t0) 								# Pone altura de la pieza en $t0.
						lb $t1, pos_pieza_y							# Pone la posición Y de la pieza en $t1.
						add $t0, $t0, $t1							# Pone (altura de la pieza) + (pos_pieza_y) en $t0.
						lb $t1, tam_tablero_y						# Pone la altura del tablero en $t1.
						blt $t0, $t1, no_ultima_fila				# Si la pieza no esta en la última salta a la etiqueta fila no_ultima_fila.
						j opcion_abajo_fijar						# Salto incondicional a la etiqueta opcion_abajo_fijar.
no_ultima_fila:	
					# - Si la pieza en juego no está en la última fila:
						# - $yprov = $y +1 y - $xprov = $x
						la $a0, pos_pieza_x							# Pone la dirección de memoria pos_pieza_x en $a0.
						la $a1, pos_pieza_y							# Pone la dirección de memoria de pos_pieza_y $a1.
						la $a2,	giro_en_juego						# Pone la dirección de memoria de giro_en_juego $a2.
						jal Act_pos_prov							# Llamada a la rutina Act_pos_prov.
						lb $t0, pos_prov_pieza_y					# Pone la posición X provisional de la pieza en $t0.
						addi $t0, $t0, 1							# Incrementa la posición X provisional en 1.
						sb $t0, pos_prov_pieza_y					# Guarda la nueva posición provisional en la dirección de memoria pos_prov_pieza_y.
						# - Genera la matriz tablero_prov
						la $a0, tablero								# Pone la dirección de memoria de tablero en $a0.
						la $a1, tablero_prov						# Pone la dirección de memoria de tablero_prov en $a1.
						la $a2, tablero_print						# Pone la dirección de memoria de tablero_print en $a2.
						jal Genera_prov								# Llamada a la rutina Genera_prov.
						# - Si la matriz tablero_prov no es factible ($v0=-1) convierte la pieza en “fija” y comprueba la existencia de filas completas.
						beq $v0, $zero, opcion_abajo_fin			# Si se generó el tablero_prov salta a la etiqueta opcion_abajo_fin.

opcion_abajo_fijar:	la $a0, pos_pieza_x								# Pone la dirección de memoria pos_pieza_x en $a0.
					la $a1, pos_pieza_y								# Pone la dirección de memoria de pos_pieza_y $a1.
					la $a2,	giro_en_juego							# Pone la dirección de memoria de giro_en_juego $a2.
					jal Act_pos_prov								# Llamada a la rutina Act_pos_prov.

					la $a0, tablero									# Pone la dirección de memoria de tablero en $a0.
					la $a1, tablero_prov							# Pone la dirección de memoria de tablero_prov en $a1.
					la $a2, tablero_print							# Pone la dirección de memoria de tablero_print en $a2.
					jal Genera_prov									# Llamada a la rutina Genera_prov.

					la $a0, tablero_prov							# Pone la dirección de memoria de tablero_prov en $a0.
					jal Fija_actual									# Llamada a la rutina Fija_actual.
					jal Limpiar_fila								# Llamada a la rutina Limpiar_fila.
					la $a0, tablero_prov							# Pone la dirección de memoria de tablero_prov en $a0.
					la $a1, tablero_print							# Pone la dirección de memoria de tablero_print en $a1.
					jal Copia_matriz								# Llamada a la rutina Copia_matriz.
					la $a1, tablero									# Pone la dirección de memoria de tablero en $a1.
					jal Copia_matriz								# Llamada a la rutina Copia_matriz.

					j jugar_nueva_pieza								# Salto incondicional a la etiqueta jugar_nueva_pieza.

opcion_abajo_fin:	add $t0, $zero, 5								# Pone un 5 en $t0.
					beq $s0, $t0, opcion_abajo						# Si la opción elegida es 5 (bajar hasta fijar) salta a la etiqueta opcion_abajo.
					la $a0, tablero_prov							# Pone la dirección de memoria de tablero_prov en $a0.
					la $a1, tablero_print							# Pone la dirección de memoria de tablero_print en $a1.
					jal Copia_matriz								# Llamada a la rutina Copia_matriz.							
					j jugando										# Salto incondicional a la etiqueta jugando.

opcion_girar:		# Girar:

					la $a0, pos_pieza_x								# Pone la dirección de memoria de pos_pieza_x en $a0.
					la $a1, pos_pieza_y								# Pone la dirección de memoria de pos_pieza_y en $a1.
					la $a2,	giro_en_juego							# Pone la dirección de memoria de giro_en_juego en $a2.
					jal Act_pos_prov								# Llamada a la rutina Act_pos_prov.

					lb $a0, pieza_en_juego							# Pone la pieza en juego en $a0.
					lb $a1, giro_prov_pieza							# Pone giro_prov_pieza en $a1.
					addi $a1, $a1, 1								# Pone el giro a realizar (giro+1) en $a1.

					addi $t0, $zero, 4								# Pone un 4 en $t0.				
					beq $a1, $t0, opcion_g_reinicia  				# Si el giro provisional es igual a 4 salta a la etiqueta opcion_g_reinicia.
opcion_giro_cont:	sb $a1, giro_prov_pieza							# Guarda el nuevo giro en la dirección de memoria giro_prov_pieza.
					jal Direccion_pieza								# Llamada a la rutina Direccion_pieza.

					la $t0, piezas_x								# Pone la dirección del vector piezas_x en $t0.
					add $t0, $t0, $v1								# Pone (dirección del vector) + (posición dentro del vector) en $t0.
					lb $t0, 0($t0) 									# Pone el tamaño de la pieza en $t0.
					lb $t1, pos_pieza_x								# Pone la posición de la pieza actual en $t1.
					add $t0, $t0, $t1								# Pone (posición de la pieza) + (tamaño de la pieza) en $t0.

					lb $t1, tam_tablero_x							# Pone el tamaño de la fila en $t1.
					bgt $t0, $t1, opcion_girar_fin					# Si la pieza con el nuevo giro queda fuera del tablero salta a la etiqueta opcion_girar_fin.

					la $a0, tablero									# Pone la dirección de memoria de tablero en $a0.
					la $a1, tablero_prov							# Pone la dirección de memoria de tablero_prov en $a1.
					la $a2, tablero_print							# Pone la dirección de memoria de tablero_print en $a2.
					jal Genera_prov									# Llamada a la rutina Genera_prov.
opcion_girar_fin:	j jugando										# Salto incondicional a la etiqueta jugando.

opcion_g_reinicia:	move $a1, $zero									# Pone un 0 en $a1.
					j opcion_giro_cont								# Salto incondicional a la etiqueta opcion_giro_cont.

opcion_salir:		# Salir:
						# - Finaliza el juego
# Fin del juego ############################################################################################

fin_del_juego: 		
					la $a0, tablero									# Pone la dirección de memoria de tablero en $a0.
					lb $a1, tam_tablero_x							# Pone el tamaño de la fila en $a1.
					lb $a2, tam_tablero_y							# Pone la altura del tablero en $a2.
					jal Imprime_tablero								# Llamada a la rutina Imprime_tablero.
					la $a0, cr										# Pone la dirección de memoria de la cadena cr en $a0.
					jal Impr_string									# Llamada a la rutina Impr_string.
					la $a0, mens_fin								# Pone la direccón de memoria de la cadena mens_fin en $a0.
					jal Impr_string									# Llamada a la rutina Impr_string.
					lw $a0, puntuacion_total						# Pone la puntuación total en $a0.
					jal Impr_int									# Llamada a la rutina Impr_int.
					
					li $v0, 10										#
					syscall 										#
																	# 
