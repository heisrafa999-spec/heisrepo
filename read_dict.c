#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*read_dict(char *filename)
{
	int		fd;
	char	*buffer;
	int		size;

	buffer = malloc(10000);
	if (!buffer)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	size = read(fd, buffer, 9999);
	if (size < 0)
		return (0);

	buffer[size] = '\0';
	close(fd);
	return (buffer);
}
