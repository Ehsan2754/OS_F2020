#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#define PATH "./tmp"
const int N = 0xff;
struct files
{
    int node;
    int number;
    int o;
    char *c[0xff];
};
int occupied = 0;
void add_file(struct files *a, int i, char *name)
{
    int j = 0;
    int k = a[i].o;
    for (; name[j] != ' '; ++j)
    {
        a[i].c[k++] = &name[j];
    }
    a[i].c[k] = (char*)'\n';
    a[i].o = k + 1;
}
void insert_dir(struct files *a, int node, char *name)
{
    for (int i = 0; i < occupied; i++)
    {

        if (a[i].node == node)
        {
            a[i].number = a[i].number + 1;
            if (a[i].number > 0)
                add_file(a, i, name);
            printf("#### node:%d\n", node);
            return;
        }
        a[occupied].node = node;
        a[occupied].number = 1;
        occupied = occupied + 1;
        add_file(a, i, name);
    }
}


int main()
{

    DIR *dir = opendir(PATH);
    struct dirent *file = readdir(dir);
    struct files *a[N];
    
    while ((file = readdir(dir)) != NULL)
    {
        insert_dir(a, file->d_ino,file->d_name);
        printf("%s %d\n", file->d_name, file->d_ino);
    }

    return 0;
}