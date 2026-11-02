EXPECTED = (
    "multiply: 0\n"
    "C:\n"
    "  50  60\n"
    " 114 140\n"
    " 178 220\n"
    "NULL: 1\n"
    "error: NULL pointer\n"
    "Wrong size: 2\n"
    "error: wrong dimensions\n"
    "Other size: 0\n"
)


def test_lab06(run_lab) -> None:
    result = run_lab("lab06_matrices")
    assert result.returncode == 0
    assert result.stdout == EXPECTED
    assert result.stderr == ""
