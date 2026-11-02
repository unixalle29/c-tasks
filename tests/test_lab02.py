import pytest


@pytest.mark.parametrize(
    ("stdin", "returncode", "stdout"),
    [
        pytest.param(
            "66\n2\n",
            0,
            "Enter ASCII code: B\n"
            "Enter volume in liters: molecules = 6.67e+25\n"
            "*\n**\n***\n****\n",
            id="valid",
        ),
        pytest.param(
            "65\n0\n",
            0,
            "Enter ASCII code: A\n"
            "Enter volume in liters: molecules = 0.00e+00\n"
            "*\n**\n***\n****\n",
            id="zero-volume",
        ),
        pytest.param("abc\n", 1, "Enter ASCII code: invalid code\n", id="bad-code"),
        pytest.param(
            "66\n-1\n",
            1,
            "Enter ASCII code: B\nEnter volume in liters: invalid volume\n",
            id="bad-volume",
        ),
    ],
)
def test_lab02(stdin: str, returncode: int, stdout: str, run_lab) -> None:
    result = run_lab("lab02_formatted_io", stdin)
    assert result.returncode == returncode
    assert result.stdout == stdout
    assert result.stderr == ""
