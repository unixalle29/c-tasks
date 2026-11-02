EXPECTED = "B\n*\n**\n***\n****\nmass = 33510.321638\n"


def test_lab02(run_lab) -> None:
    result = run_lab("lab02_formatted_io")
    assert result.returncode == 0
    assert result.stdout == EXPECTED
    assert result.stderr == ""
