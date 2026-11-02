import pytest

VALID_INPUT = "3 4 5\n4 4 4\n5 5 5\n2 3 4\n"


def test_lab08_valid(run_lab) -> None:
    result = run_lab("lab08_structs", VALID_INPUT)
    assert result.returncode == 0
    assert "Ivan Ivanov: 3.00 4.00 5.00 average 4.00" in result.stdout
    assert "Petr Petrov: 4.00 4.00 4.00 average 4.00" in result.stdout
    assert "Anna Sidorova: 5.00 5.00 5.00 average 5.00" in result.stdout
    assert "Olga Smirnova: 2.00 3.00 4.00 average 3.00" in result.stdout
    assert "Class averages: 3.50 4.00 4.50" in result.stdout


@pytest.mark.parametrize(
    "stdin",
    [
        pytest.param("6 4 5\n4 4 4\n5 5 5\n2 3 4\n", id="grade-too-high"),
        pytest.param("1 4 5\n4 4 4\n5 5 5\n2 3 4\n", id="grade-too-low"),
        pytest.param("3 4 5\n", id="not-enough-grades"),
        pytest.param("abc\n", id="not-numbers"),
    ],
)
def test_lab08_invalid(run_lab, stdin: str) -> None:
    result = run_lab("lab08_structs", stdin)
    assert result.returncode == 1
    assert "invalid grades" in result.stdout
