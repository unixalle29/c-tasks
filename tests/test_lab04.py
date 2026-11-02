import pytest


@pytest.mark.parametrize(
    ("stdin", "returncode", "stdout"),
    [
        pytest.param("1 1\n", 0, "Enter day and month: Switch: 364\nArray: 364\n", id="january-1"),
        pytest.param("31 12\n", 0, "Enter day and month: Switch: 0\nArray: 0\n", id="december-31"),
        pytest.param("28 2\n", 0, "Enter day and month: Switch: 306\nArray: 306\n", id="february-28"),
        pytest.param("29 2\n", 1, "Enter day and month: invalid date\n", id="february-29"),
        pytest.param("0 1\n", 1, "Enter day and month: invalid date\n", id="zero-day"),
        pytest.param("1 13\n", 1, "Enter day and month: invalid date\n", id="bad-month"),
        pytest.param("abc\n", 1, "Enter day and month: invalid date\n", id="not-numbers"),
    ],
)
def test_lab04(stdin: str, returncode: int, stdout: str, run_lab) -> None:
    result = run_lab("lab04_arrays", stdin)
    assert result.returncode == returncode
    assert result.stdout == stdout
    assert result.stderr == ""
