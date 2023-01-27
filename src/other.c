/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-quentin.cialone
** File description:
** other.c
*/
void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
