import pytest


@pytest.mark.parametrize(
    ("stdin", "returncode", "stdout"),
    [
        pytest.param("5\n3 1 4 1 5\n", 0, "N: min = 1\nmax = 5\nsum = 14\n", id="basic"),
        pytest.param("1\n-7\n", 0, "N: min = -7\nmax = -7\nsum = -7\n", id="single-negative"),
        pytest.param("3\n0 0 0\n", 0, "N: min = 0\nmax = 0\nsum = 0\n", id="zeros"),
        pytest.param("0\n", 1, "N: wrong N\n", id="zero-count"),
        pytest.param("101\n", 1, "N: wrong N\n", id="too-many"),
        pytest.param("abc\n", 1, "N: wrong N\n", id="bad-count"),
        pytest.param("2\n1\nx\n", 1, "N: wrong number\n", id="bad-value"),
    ],
)
def test_lab04(stdin: str, returncode: int, stdout: str, run_lab) -> None:
    result = run_lab("lab04_arrays", stdin)
    assert result.returncode == returncode
    assert result.stdout == stdout
    assert result.stderr == ""
