# Solution for question 10
# Considered alphabet: 
#    ascii_letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
#    ascii_lowercase = 'abcdefghijklmnopqrstuvwxyz'

#strings used for testing: "EntradA", "Sa4dA", "tesTando"


.data 

	#Declaring a string	
	main_string: .ascii "EntradA"

	
.text 

	Main:

		# A counter is necessary for the iteration
		addi $s0, $s0, 0 # $s0 = byte 0 first "i" iterator

	# Now a loop is necessary in order to iterate through the string and turn it all into lowercase


		loop_1:
			# main_string[0], main_string[1] until the end of the loop...
			lb $s1, main_string($s0) # loading the byte value of the string;	
			beq $s1, 0, sort
			j upper_to_lower

		
		sort: # decrescent insertion sort 

        	li $t0, 1 # i = 1, it will be the counter 
			first_loop:
				lb $s3, main_string($t0) # $s1 = memory[i]
				beq $s3, 0, the_end # End Condition
				addi $t1, $t0, -1 
				
				intermidiate_loop:
					lb $s2, main_string($t1) # $s2 = memory[j]
					blt $t1, $zero, second_loop # Se $t1 < 0, sair do loop _j
					ble $s3, $s2, second_loop # Se $s1 <= $s2, sair do loop_j
					
					addi $t2, $t1, 1 # $t2 = $t1 + 1 (j + 1)
					sb $s2, main_string($t2) # Armazenar o caractere de $s2 em memory[j+1]
					
					addi $t1, $t1, -1 # Subtrair 1 de j e voltar para o loop_j
					j intermidiate_loop
				
			second_loop:
				addi $t2, $t1, 1 # $t2 = $t1 + 1 (j + 1)
				sb $s3, main_string($t2) # Armazenar o caractere de $s1 em memory[j+1]
						
				addi $t0, $t0, 1 # Incrementar $t0 e voltar para o loop_i
				j first_loop 





		#Script ended or there was a non-letter character in the string;		
	the_end:
		li $v0, 4 
		la $a0, main_string 	
		syscall

		li $v0,10
		syscall



#Subroutine Functions



	upper_to_lower:

		# So uppercase letters range from 65 to 90 in ASCII code, wich is the way they are stored into the MIPS assembly. If they are less than 65 
		#they'll be considered non-character or another random character,
		first_check: #Uppercase or not
			blt $s1, 'A', exit_func #If $s1 < 'A' it means that is not a letter
			bgt $s1, 'Z', second_check #If $s1 > 'Z' it means that is lowercase or another  random character
			#If this section is still running it means that's is a uppercase letter and it can be simply converted by adding it 32;
			addi $s1, $s1, 32
			sb $s1, main_string($s0)
			j loop_1

		second_check:
			blt $s1, 'a', exit_func #If $s1 < 'a' it means that is not a letter
			bgt $s1, 'z', exit_func #If $s1 > 'z' it means that is not a letter
			addi $s0, $s0, 1
			j loop_1



		exit_func:

			li $v1, 1
			j the_end



