import pytest


@pytest.mark.parametrize(
    ("stdin", "returncode", "stdout"),
    [
        pytest.param("5\n", 0, "n: factorial = 120\ndigit sum = 5\n", id="basic"),
        pytest.param("0\n", 0, "n: factorial = 1\ndigit sum = 0\n", id="zero"),
        pytest.param("1\n", 0, "n: factorial = 1\ndigit sum = 1\n", id="one"),
        pytest.param(
            "20\n",
            0,
            "n: factorial = 2432902008176640000\ndigit sum = 2\n",
            id="max",
        ),
        pytest.param("21\n", 1, "n: wrong n\n", id="too-large"),
        pytest.param("-1\n", 1, "n: wrong n\n", id="negative"),
        pytest.param("abc\n", 1, "n: wrong n\n", id="not-number"),
    ],
)
def test_lab10(stdin: str, returncode: int, stdout: str, run_lab) -> None:
    result = run_lab("lab10_recursion", stdin)
    assert result.returncode == returncode
    assert result.stdout == stdout
    assert result.stderr == ""
