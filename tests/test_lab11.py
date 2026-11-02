import pytest


@pytest.mark.parametrize(
    ("stdin", "returncode", "stdout"),
    [
        pytest.param("2 + 3\n", 0, "5.00\n", id="add"),
        pytest.param("8 - 3\n", 0, "5.00\n", id="sub"),
        pytest.param("4 * 2.5\n", 0, "10.00\n", id="mul"),
        pytest.param("8 / 2\n", 0, "4.00\n", id="div"),
        pytest.param("1 / 0\n", 1, "division by zero\n", id="div-zero"),
        pytest.param("1 % 2\n", 1, "unknown operation\n", id="unknown"),
        pytest.param("abc\n", 1, "wrong input\n", id="bad-input"),
    ],
)
def test_lab11(stdin: str, returncode: int, stdout: str, run_lab) -> None:
    result = run_lab("lab11_function_pointers", stdin)
    assert result.returncode == returncode
    assert result.stdout == stdout
    assert result.stderr == ""
