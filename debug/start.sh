cp -fr ../includes/* ./includes/ &&
cp -fr ../libftprintf.a ./ &&
gcc -Wall -Werror -Wextra -g -O0 -I ./includes/ main.c -o test -L. -lftprintf -lm
