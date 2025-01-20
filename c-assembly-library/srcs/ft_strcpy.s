			section		.text
			global		_ft_strcpy

_ft_strcpy:
			xor			rcx, rcx

_strcpy_loop:
			mov			dl, byte [rsi + rcx]
			cmp			dl, 0
			je			_strcpy_end
			mov			byte [rdi + rcx], dl
			inc			rcx
			jmp			_strcpy_loop

_strcpy_end:
			mov			byte [rdi + rcx], 0
			mov			rax, rdi
			ret
