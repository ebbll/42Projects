			section		.text
			global		_ft_strcmp

_ft_strcmp:
			xor			rcx, rcx

_strcmp_loop:
			mov			dl, byte [rdi + rcx]

			cmp			dl, byte [rsi + rcx]
			jne			_strcmp_ret
			cmp			dl , 0
			je			_strcmp_zero
			inc			rcx
			jmp			_strcmp_loop

_strcmp_ret:
			xor			rax, rax
			xor			rbx, rbx
			mov			al, byte[rdi + rcx]
			mov			bl, byte[rsi + rcx]
			sub			rax, rbx
			ret

_strcmp_zero:
			xor			rax, rax
			ret
