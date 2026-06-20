#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    char *s = argv[1];
    size_t s_len = strlen(s);
    if (s_len == 0) return 0;

    char *buf = NULL;
    size_t buf_len = 0;
    char tmp[BUF_SIZE];
    ssize_t n;

    while ((n = read(0, tmp, BUF_SIZE)) > 0) {
        // Expand buffer to hold new data
        char *new_buf = realloc(buf, buf_len + n);
        if (!new_buf) return 1;
        buf = new_buf;
        memcpy(buf + buf_len, tmp, n);
        buf_len += n;

        // Process buffer
        char *pos;
        while ((pos = memmem(buf, buf_len, s, s_len)) != NULL) {
            write(1, buf, pos - buf); // Write before the match
            size_t consumed = (pos - buf) + s_len;
            memmove(buf, buf + consumed, buf_len - consumed);
            buf_len -= consumed;
        }

        // Keep at most s_len - 1 bytes in case a match is split
        if (buf_len >= s_len) {
            size_t keep = s_len - 1;
            write(1, buf, buf_len - keep);
            memmove(buf, buf + (buf_len - keep), keep);
            buf_len = keep;
        }
    }
    // Write remaining buffer
    if (buf_len > 0) write(1, buf, buf_len);
    free(buf);
    return 0;
}