import pytest


def test_lab11_all_operations(run_lab) -> None:
    result = run_lab("lab11_function_pointers", "2 + 3\n8 / 2\n1 / 0\n5 % 2\nq\n")
    assert result.returncode == 0
    assert result.stdout == (
        "Enter a op b (q to quit): result = 5.00\n"
        "Enter a op b (q to quit): result = 4.00\n"
        "Enter a op b (q to quit): division by zero\n"
        "Enter a op b (q to quit): unknown operation\n"
        "Enter a op b (q to quit): "
    )


def test_lab11_subtract_and_multiply(run_lab) -> None:
    result = run_lab("lab11_function_pointers", "5 - 2\n3 * 4\nq\n")
    assert result.returncode == 0
    assert "result = 3.00" in result.stdout
    assert "result = 12.00" in result.stdout


def test_lab11_quit_immediately(run_lab) -> None:
    result = run_lab("lab11_function_pointers", "q\n")
    assert result.returncode == 0
    assert result.stdout == "Enter a op b (q to quit): "


@pytest.mark.parametrize("stdin", ["abc\n", "2 +\n"])
def test_lab11_invalid_input(run_lab, stdin: str) -> None:
    result = run_lab("lab11_function_pointers", stdin)
    assert result.returncode == 1
    assert "invalid input" in result.stdout
