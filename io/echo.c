#include <unistd.h>
#include <fcntl.h>

int main ()
{
    char buf[512];
    int nread;
    while ((nread = read(0, buf, 512)) > 0) {
        write(1, buf, nread);
    }
    return 0;
}
