 
;TEXT SECTION
 
global main
 
			section			.txt
 
			extern			printf
 
main:		nop										;main PROC
			push			rbp
			mov				rbp,rsp
			push			3						;emit numbers
			pop				qword [A]				;print assignments
			push			4						;emit numbers
			pop				qword [B]				;print assignments
			push			3						;emit numbers
			pop				qword [D]				;print assignments
			push			qword [A]				;print identifiers
			push			qword [B]				;print identifiers
			pop				rbx						;print multiplcation/division
			pop				rax
			mov				rdx,0					;move a 0 into rdx
			imul			rax,rbx					;multiply the two register
			push			rax
			push			qword [A]				;print identifiers
			push			qword [D]				;print identifiers
			pop				rbx						;print addition ops
			pop				rax
			add				rax,rbx					;adds the contents of rax and rbx
			push			rax
			pop				rbx						;print multiplcation/division
			pop				rax
			mov				rdx,0					;move a 0 into rdx
			idiv				rbx					;multiply the two register
			push				rax
			pop				qword [E]				;print assignments
			push			qword [A]				;print identifiers
			mov				rdi,_INT_
			pop				rsi
			mov				rax,0
			call			printf
			mov				rdi,_STR_
			mov				rsi,_CRLF_
			mov				rax,0
			call			printf
			push			qword [B]				;print identifiers
			mov				rdi,_INT_
			pop				rsi
			mov				rax,0
			call			printf
			mov				rdi,_STR_
			mov				rsi,_CRLF_
			mov				rax,0
			call			printf
			push			qword [E]				;print identifiers
			mov				rdi,_INT_
			pop				rsi
			mov				rax,0
			call			printf
			mov				rdi,_STR_
			mov				rsi,_CRLF_
			mov				rax,0
			call			printf
			mov				rsp,rbp
			pop				rbp
			mov				rax,0
			ret
 
;BSS Section
 
			section				.bss
 
A:			resq			1
B:			resq			1
E:			resq			1
D:			resq			1
 
;DATA Section
 
			section				.data
_INT_    :	db					"%i",0x0
_STR_    :	db					"%s",0x0
_CRLF_   :	db					0xa,0x0
 
