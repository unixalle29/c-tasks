EXPECTED = "5 4 3 2 1 \n"


def test_lab09(run_lab) -> None:
    result = run_lab("lab09_list")
    assert result.returncode == 0
    assert result.stdout == EXPECTED
    assert result.stderr == ""
