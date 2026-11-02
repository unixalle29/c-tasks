import pytest


@pytest.mark.parametrize(
    ("stdin", "stdout"),
    [
        pytest.param("AB\033", "Enter text, ESC to stop:\n65 66 \n", id="two-chars"),
        pytest.param("\033", "Enter text, ESC to stop:\n\n", id="empty"),
        pytest.param("\n\033", "Enter text, ESC to stop:\n10 \n", id="enter"),
        pytest.param("a\033", "Enter text, ESC to stop:\n97 \n", id="one-char"),
    ],
)
def test_lab03(stdin: str, stdout: str, run_lab) -> None:
    result = run_lab("lab03_loops", stdin)
    assert result.returncode == 0
    assert result.stdout == stdout
    assert result.stderr == ""
