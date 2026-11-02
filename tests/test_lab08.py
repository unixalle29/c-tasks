EXPECTED = (
    "Petr Petrov, grade 5, born 2004\n"
    "Olga Smirnova, grade 5, born 2005\n"
    "Ivan Ivanov, grade 4, born 2005\n"
    "Anna Sidorova, grade 3, born 2006\n"
)


def test_lab08(run_lab) -> None:
    result = run_lab("lab08_structs")
    assert result.returncode == 0
    assert result.stdout == EXPECTED
    assert result.stderr == ""
