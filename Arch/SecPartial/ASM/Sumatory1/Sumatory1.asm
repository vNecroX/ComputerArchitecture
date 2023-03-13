.ORG 0100H
	MVI A, 00H 		;A = N -> A == 00H
      INR A			;A++ -> 01H > 00H
	MOV B, A		
	INR B			;B = 02H
	CALL SUMATORY1
	HLT
	
SUMATORY1:
	ADD B			;A += B
	INR B			;B = 03H. . .
	JMP SUMATORY1
	
	
	