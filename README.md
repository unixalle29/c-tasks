# c-tasks

12 лабораторных по C (ПетрГУ, «Информатика»). Одна лаба — один файл в `src/`.

## Сборка

```bash
make        # всё соберётся в build/
make clean  # удалить build/
```

Нужны `gcc`, `make` и [uv](https://docs.astral.sh/uv/) для тестов.

## Тесты

```bash
uv sync
uv run pytest
# или
make test
```

Тесты лежат в `tests/`, собирают программы и проверяют вывод и коды возврата.

## Лабы

| # | Файл | Задание |
|---|---|---|
| 1 | `lab01_linux.sh` | команды Linux: файлы, редиректы, фон/`wait` |
| 2 | `lab02_formatted_io.c` | ввод кода → ASCII-символ; объём воды → молекулы; звёздочки |
| 3 | `lab03_loops.c` | коды символов в oct/dec/hex до ESC |
| 4 | `lab04_arrays.c` | дни до Нового года двумя способами: `switch` и массив |
| 5 | `lab05_strings.c` | строки до точки → предложение, `malloc`/`fgets`/`free` |
| 6 | `lab06_matrices.c` | A 3×4 × B 4×2, функция с указателями и кодами 0/1/2 |
| 7 | `lab07_files.c` | матрицы из файла, умножение, вывод в файл, ближайший к среднему |
| 8 | `lab08_structs.c` | `student` с 3 оценками, средние и средние по предметам |
| 9 | `lab09_list.c` | связный список студентов: add/sort/delete/insert/search/count |
| 10 | `lab10_recursion.c` | рекурсивная степень `double` в `int` |
| 11 | `lab11_function_pointers.c` | калькулятор на указателях на функции, выход по `q` |
| 12 | `lab12_preprocessor.c` | заголовок `harmonic.h`, макрос гармонического среднего |

## Запуск

```bash
./build/lab02_formatted_io
./build/lab04_arrays
./build/lab06_matrices
./build/lab08_structs
./build/lab09_list
./build/lab12_preprocessor
```

С вводом:

```bash
printf '66\n2\n' | ./build/lab02_formatted_io
printf 'n\nAB\033' | ./build/lab03_loops
printf '1 1\n' | ./build/lab04_arrays
printf 'Hello\nworld\n.\n' | ./build/lab05_strings
printf 'Ivanov Ivan\n3 4 5\nPetrov Petr\n4 4 4\nSidorova Anna\n5 5 5\nSmirnova Olga\n2 3 4\n' |
    ./build/lab08_structs
printf '2 10\n' | ./build/lab10_recursion
printf '2 + 3\nq\n' | ./build/lab11_function_pointers
printf '3\n1\n2\n4\n' | ./build/lab12_preprocessor
```

Lab 7 читает `input.txt` и пишет `output.txt`. Формат: `N M`, матрица A, `K L`, матрица B.

```bash
./build/lab07_files
cat output.txt
```

Lab 1 — интерактивная лаба. Скрипт показывает неинтерактивную часть, а в
`src/lab01_report.md` лежит отчёт с командами и пояснениями для ручных пунктов:

```bash
./src/lab01_linux.sh
```
