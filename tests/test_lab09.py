def test_lab09_count_initial_student(run_lab) -> None:
    result = run_lab("lab09_list", "7\n0\n")
    assert result.returncode == 0
    assert "count: 1" in result.stdout


def test_lab09_add_and_print(run_lab) -> None:
    result = run_lab("lab09_list", "1\nPetrov\nPetr\n5 5 5\n2\n0\n")
    assert result.returncode == 0
    assert "Petr Petrov: 5.00 5.00 5.00 average 5.00" in result.stdout


def test_lab09_add_and_count(run_lab) -> None:
    result = run_lab("lab09_list", "1\nPetrov\nPetr\n5 5 5\n7\n0\n")
    assert result.returncode == 0
    assert "count: 2" in result.stdout


def test_lab09_sort_by_surname(run_lab) -> None:
    result = run_lab("lab09_list", "1\nAntonov\nAnton\n3 3 3\n3\n2\n0\n")
    assert result.returncode == 0
    assert result.stdout.index("Anton Antonov") < result.stdout.index("Ivan Ivanov")


def test_lab09_delete_existing(run_lab) -> None:
    result = run_lab("lab09_list", "4\nIvanov\n7\n0\n")
    assert result.returncode == 0
    assert "deleted" in result.stdout
    assert "count: 0" in result.stdout


def test_lab09_delete_missing(run_lab) -> None:
    result = run_lab("lab09_list", "4\nNobody\n0\n")
    assert result.returncode == 0
    assert "not found" in result.stdout


def test_lab09_search_found_and_missing(run_lab) -> None:
    result = run_lab("lab09_list", "6\nIvanov\n6\nNobody\n0\n")
    assert result.returncode == 0
    assert "Ivan Ivanov" in result.stdout
    assert "not found" in result.stdout


def test_lab09_insert_after(run_lab) -> None:
    result = run_lab("lab09_list", "5\nIvanov\nSidorov\nAnna\n4 4 4\n2\n0\n")
    assert result.returncode == 0
    assert "inserted" in result.stdout
    assert result.stdout.index("Ivan Ivanov") < result.stdout.index("Anna Sidorov")


def test_lab09_insert_after_missing(run_lab) -> None:
    result = run_lab("lab09_list", "5\nNobody\n0\n")
    assert result.returncode == 0
    assert "not found" in result.stdout
