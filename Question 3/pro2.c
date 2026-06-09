#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>
#include<dirent.h>

int main()
{
	DIR *d;
	struct stat s;
	struct dirent *dir;

	d = opendir(".");

	if(d == NULL)
	{
		printf("error opening directory");
		return 1;
	}

	while((dir = readdir(d)) != NULL)
	{
		stat(dir->d_name,&s);
		printf("File name :%s\n", dir->d_name);
		printf("File size: %ld bytes\n", s.st_size);
		printf("Inode number: %ld\n",s.st_ino);
		printf("File permission: %o\n",s.st_mode & 0777);
		printf("No of links :%ld\n", s.st_nlink);
	}
	closedir(d);
	return 0;
}
