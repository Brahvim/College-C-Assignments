int main(const int p_count, char const **p_args) {
    if (p_count < 2)
        puts("This program prints arguments provided to it in reverse. Please consider providing some.");
    else
        for (int i = p_count - 1; i > 0; i--)
            puts(p_args[i]);
}
