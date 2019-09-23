#include <stdio.h>

int main() {
    char c;
    int total = 1, vogal = 0;
    scanf("%c", &c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        vogal++;
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        vogal++;
    while (c != '.') {
        scanf("%c", &c);
        total++;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vogal++;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vogal++;
    }

    printf("%d/%d", vogal, total);
    return 0;
}
