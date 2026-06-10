#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include<errno.h>
int main()
{
    mode_t mask, perm;
    char filename[50];

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter umask (octal): ");
    scanf("%o", &mask);

    mode_t oldmask = umask(mask);

    printf("Old umask = %03o\n", oldmask);

    int fd = creat(filename, 0777);

    if(fd < 0)
    {
        printf("Error creating file\n");
        return 1;
    }

    close(fd);

    printf("Enter new permission (octal): ");
    scanf("%o", &perm);

    chmod(filename, perm);

    printf("Permissions changed to %03o\n", perm);

    return 0;
}
