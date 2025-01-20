			section		.text
			global		_ft_strlen

_ft_strlen:
			xor			rax, rax

_strlen_loop:
			cmp			byte [rdi + rax], 0x0
			je			_strlen_end
			inc			rax
			jmp			_strlen_loop

_strlen_end:
			ret
