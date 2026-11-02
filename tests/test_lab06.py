EXPECTED = "  50  60\n 114 140\n 178 220\n"


def test_lab06(run_lab) -> None:
    result = run_lab("lab06_matrices")
    assert result.returncode == 0
    assert result.stdout == EXPECTED
    assert result.stderr == ""
