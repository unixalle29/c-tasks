# c-tasks

12 лабораторных по C (ПетрГУ, «Информатика»). Одна лаба — один файл в `src/`.

## Сборка

```bash
make        # всё соберётся в build/
make clean  # удалить build/
```

Нужны `gcc`, `make` и [uv](https://docs.astral.sh/uv/).

## Тесты

```bash
uv sync
uv run pytest
# или
make test
```

Тесты на Python/pytest лежат в `tests/`, сами собирают C-программы и проверяют вывод и коды возврата. CI: `.github/workflows/ci.yml`.

## Лабы

| # | Файл | Что делает |
|---|---|---|
| 1 | `lab01_linux.sh` | команды Linux |
| 2 | `lab02_formatted_io.c` | ASCII-символ, звёздочки, масса шара |
| 3 | `lab03_loops.c` | символы до ESC и их ASCII-коды |
| 4 | `lab04_arrays.c` | min, max и сумма массива |
| 5 | `lab05_strings.c` | переворот строки через `malloc`/`free` |
| 6 | `lab06_matrices.c` | умножение матриц 3×4 и 4×2 |
| 7 | `lab07_files.c` | чтение `input.txt`, запись `output.txt` |
| 8 | `lab08_structs.c` | структуры и сортировка студентов |
| 9 | `lab09_list.c` | односвязный список |
| 10 | `lab10_recursion.c` | факториал и сумма цифр |
| 11 | `lab11_function_pointers.c` | калькулятор на указателях на функции |
| 12 | `lab12_preprocessor.c` | макросы и `#ifdef DEBUG` |

## Запуск

```bash
./build/lab02_formatted_io
./build/lab06_matrices
./build/lab08_structs
./build/lab09_list
./build/lab12_preprocessor
```

С вводом:

```bash
printf 'AB\033' | ./build/lab03_loops
printf '5\n3 1 4 1 5\n' | ./build/lab04_arrays
printf 'hello\n' | ./build/lab05_strings
printf '5\n' | ./build/lab10_recursion
printf '8 / 2\n' | ./build/lab11_function_pointers
```

Лаба 7 читает `input.txt` и пишет `output.txt`. Формат: первая строка — N, вторая — N чисел.

```bash
./build/lab07_files
cat output.txt
```

Лаба 1:

```bash
./src/lab01_linux.sh
```

Отладка в лабе 12:

```bash
make clean && make CFLAGS="-std=c11 -Wall -Wextra -DDEBUG"
./build/lab12_preprocessor
```

