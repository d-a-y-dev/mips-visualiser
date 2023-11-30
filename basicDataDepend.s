		.text
__start:
		addiu $v0, $zero, 10 # to R2 RT
		addiu $t0, $zero, 5 # to R8 RT
        addu $s0, $t0, $t0 # to R16, use R8 RD & RT
        addiu $t1, $zero, 10 # R9
		syscall

		#edge # Handle data depend on R8
		#addiu $t0, $t1, 10 # to R8(RT), use R9(RS)
		#addu $t0, $v, $t0 # to R8(RD), use R2(RS) & R8(RT) #SAME RD and RT
