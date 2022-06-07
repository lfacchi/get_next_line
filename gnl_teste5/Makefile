all:


my:
	@clear
	@gcc -g3  main.c get_next_line_utils.c  get_next_line.c 
	@valgrind --leak-check=full --show-leak-kinds=all --read-var-info=yes ./a.out
