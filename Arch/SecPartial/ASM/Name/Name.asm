.DEFINE
	SCREEN E000H

.DATA 1000H
	DB 'E','S','T','E','B','A','N'

.ORG 0100H
	LXI D, 1000H     
	LXI B, SCREEN

S_SCREEN:
	LDAX D           			;A<-Pantalla, D y E
	STAX B				;Pantalla<-B y C
	INX B	
	INX D
	CPI 0					;NULL, End 
	JNZ S_SCREEN
	HLT