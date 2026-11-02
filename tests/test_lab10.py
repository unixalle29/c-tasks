import pytest


@pytest.mark.parametrize(
    ("stdin", "returncode", "stdout"),
    [
        pytest.param(
            "2 10\n",
            0,
            "Enter base and exponent: power = 1024.000000\n"
            "0^5 = 0.000000\n"
            "5^0 = 1.000000\n",
            id="positive",
        ),
        pytest.param(
            "0 5\n",
            0,
            "Enter base and exponent: power = 0.000000\n"
            "0^5 = 0.000000\n"
            "5^0 = 1.000000\n",
            id="zero-base",
        ),
        pytest.param(
            "5 0\n",
            0,
            "Enter base and exponent: power = 1.000000\n"
            "0^5 = 0.000000\n"
            "5^0 = 1.000000\n",
            id="zero-exp",
        ),
        pytest.param(
            "2 -2\n",
            0,
            "Enter base and exponent: power = 0.250000\n"
            "0^5 = 0.000000\n"
            "5^0 = 1.000000\n",
            id="negative-exp",
        ),
        pytest.param("abc\n", 1, "Enter base and exponent: invalid input\n", id="bad-input"),
    ],
)
def test_lab10(stdin: str, returncode: int, stdout: str, run_lab) -> None:
    result = run_lab("lab10_recursion", stdin)
    assert result.returncode == returncode
    assert result.stdout == stdout
    assert result.stderr == ""
