#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> // For S_ISIR and stat()
#include <unistd.h>   // For stat()
#include <string.h>

int main()
{
    DIR *folder;

    char path[] = "../";
    folder = opendir(path);

    if (folder == NULL)
    {
        printf("No such folder exists. Please try again.");
        return 0;
    }

    while (1)
    {
        struct dirent *entry;
        entry = readdir(folder);
        if (entry == NULL)
        {
            return 0;
        }

        // skip . and ..
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        char fullPath[1000];
        sprintf(fullPath, "%s/%s", path, entry->d_name);

        struct stat info;
        stat(fullPath, &info);

        if (S_ISDIR(info.st_mode)) {
            printf("Subdirectory: %s\n", fullPath);
        }
    }
}