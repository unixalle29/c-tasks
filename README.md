# c-tasks

Лабы по C, ПетрГУ.

## Сборка

```bash
make
make clean
```

## Тесты

```bash
uv sync
uv run pytest
```

## Лабы

- `lab01_linux.sh` — Linux
- `lab02_formatted_io.c` — ASCII, молекулы, звёздочки
- `lab03_loops.c` — коды символов до ESC
- `lab04_arrays.c` — дни до Нового года
- `lab05_strings.c` — строки до точки
- `lab06_matrices.c` — матрицы 3×4 и 4×2
- `lab07_files.c` — матрицы из файла
- `lab08_structs.c` — студенты
- `lab09_list.c` — связный список
- `lab10_recursion.c` — рекурсивная степень
- `lab11_function_pointers.c` — калькулятор
- `lab12_preprocessor.c` — гармоническое среднее

## Запуск

```bash
./build/lab02_formatted_io
./build/lab04_arrays
./build/lab06_matrices
./build/lab08_structs
./build/lab09_list
./build/lab12_preprocessor
```

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

`lab07_files`: `input.txt` → `output.txt`. Формат: `N M`, матрица A, `K L`, матрица B.

```bash
./build/lab07_files
cat output.txt
```

`lab01_linux.sh`:

```bash
./src/lab01_linux.sh
```
