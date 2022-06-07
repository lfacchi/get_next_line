/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Creatqed: 2022/05/10 23:17:13 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/27 11:54:47 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;
	char *aux;

	if (fd < 0 || fd > 256 || BUFFER_SIZE < 0)
	{
		printf("entrou");
		return (NULL);
	}
	if (!buffer)
		buffer = ft_strdup("");
	aux = ft_no_line_join(fd,buffer);
	line = ft_join_line(aux);
	buffer = ft_cut(aux);
	if (line != aux)
		free(aux);
	if (ft_strlen(line) == 0 && buffer == NULL)
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	return (line);
}

char *ft_no_line_join(int fd, char *buffer)
{
	char *aux_buffer;
	int nbytes;
	char *temp;

	nbytes = 1;
	aux_buffer = malloc((BUFFER_SIZE + 1));
	ft_memset(aux_buffer,0,BUFFER_SIZE + 1);
	while (check_line(aux_buffer) == 0 && nbytes != 0)
	{
		nbytes = read(fd,aux_buffer,BUFFER_SIZE);
		if (nbytes < 0)
		{
			free(aux_buffer);
			return(NULL);
		}
		aux_buffer[nbytes] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer,aux_buffer);
		free(temp);
	}
	free(aux_buffer);
	return (buffer);
}
char 	*ft_cut(char *buffer)
{
	char	*nbuffer;
	char	*temp;

	if (!*buffer)
	{
		return(NULL);
	}
	temp = ft_strchr(buffer, '\n');
	if (temp ==  NULL)
	{
		return (NULL);
	}
	nbuffer = malloc(sizeof(char) * (ft_strlen(temp + 1) + 1));
	nbuffer = ft_memcpy(nbuffer,(temp + 1), ft_strlen(temp + 1));
	nbuffer[ft_strlen(temp + 1)] = '\0';
	if (*buffer == '\0' )
	{
		return (NULL);
	}
	return (nbuffer);
}
char *ft_join_line(char *line)
{
	char *temp;
	int pos;

	pos = 0;
	temp = ft_strchr(line,'\n');
	if (temp == NULL)
		pos = (int)ft_strlen(line);
	else
	{
		while(line[pos])
		{
			if (line[pos] == '\n')
			    break;
		    pos++;
		}
	}
	if (check_line(line) == 1)
	{
		temp = (char *)malloc(sizeof(char) * (pos + 2));
		temp = ft_memcpy(temp,line,pos + 1);
		temp[pos + 1] = '\0';
		return (temp);
	}
	else
		return (line);
}