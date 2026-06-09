#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>

int main()
{
	DIR *d;
	struct dirent *dir;
	struct stat s;

	d = opendir(".");

	if(d == NULL)
	{
		printf("Cannot open directory");
		return 1;
	}

	while((dir = readdir(d)) != NULL)
	{
		stat(dir->d_name, &s);
		if(s.st_size == 0)
		{
			remove(dir->d_name);
			printf("Remove empty file : %s\n",dir->d_name);
		}
	}
	closedir(d);
}
