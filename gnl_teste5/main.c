#include "get_next_line.h"

/* 
int main()
{
	static int c = 1;

	
	// Single fd

	// size_t len =  sizeof(file_list)/sizeof(char *);

	for (size_t i = 1; i < 3; i++)
	{
		c = 1;
		int fd = open(file_list[i], O_RDONLY);
		char *p;
		for (int j = 0; j < 11; j++)
		{
			p = get_next_line(fd);
			printf("%s\n", p);
			if (p == NULL)
				break;
			c++;
			free(p);
		}
		// free(p);
		close(fd);
	}
} */
/* int main()
{

	int fd = open("tests/41_with_nl", O_RDONLY);
	// char *bufferteste = "foo\nbarbaz";
	char *teste = get_next_line(fd);
	printf("\nretorno:-%s-", teste);
	// free(teste);
	teste = get_next_line(fd);
	printf("\nretorno:-%s-", teste);
	// free(teste);
	teste = get_next_line(fd);
	printf("\nretorno:-%s-", teste);
	// free(teste);
	teste = get_next_line(fd);
	printf("\nretorno:-%s-", teste);
	// free(teste);
	teste = get_next_line(fd);
	printf("\nretorno:-%s-", teste);
	// free(teste);
	teste = get_next_line(fd);
	printf("\nretorno:-%s-", teste);
	free(teste);
	close(fd);
	// printf("\nbuffer:-%s-", bufferteste);
	// bufferteste = ft_cut(bufferteste);
	// printf("\nft_cut:%s",bufferteste);

} */
int main()
{
	// char *line = "";
	char *aux_line;
	char *file_list[] = {\
	"gnlTester/files/41_no_nl",\
	"gnlTester/files/41_with_nl",\
	"gnlTester/files/42_no_nl",\
	"gnlTester/files/42_with_nl",\
	"gnlTester/files/43_no_nl",\
	"gnlTester/files/43_with_nl",
	"gnlTester/files/alternate_line_nl_no_nl",\
	"gnlTester/files/alternate_line_nl_no_nl",\
	"gnlTester/files/alternate_line_nl_with_nl",\
	"gnlTester/files/multiple_nlx5",\
	"gnlTester/files/multiple_line_with_nl",\
	"gnlTester/files/multiple_line_no_nl",\
	"gnlTester/files/empty",\
	"gnlTester/files/big_line_with_nl",\
	"gnlTester/files/big_line_no_nl"};

	int i = 12;
	int fd = open(file_list[i], O_RDONLY);
	printf("\nTeste: %s", (file_list[i] + 16));
	for (int i = 0;i <= 11; i++)
	{
		aux_line = get_next_line(fd);
		printf("\n-%s-", aux_line);
		free(aux_line);
	}

	close(fd);

}
