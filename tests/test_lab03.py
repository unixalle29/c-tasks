import pytest


@pytest.mark.parametrize(
    ("stdin", "stdout"),
    [
        pytest.param(
            "AB\033",
            "Enter text, ESC to stop:\nA: oct=101 dec=65 hex=41\nB: oct=102 dec=66 hex=42\n",
            id="two-chars",
        ),
        pytest.param("a\033", "Enter text, ESC to stop:\na: oct=141 dec=97 hex=61\n", id="one-char"),
        pytest.param("0\033", "Enter text, ESC to stop:\n0: oct=60 dec=48 hex=30\n", id="digit"),
        pytest.param("\n\033", "Enter text, ESC to stop:\n", id="enter-skipped"),
        pytest.param("\033", "Enter text, ESC to stop:\n", id="esc-only"),
    ],
)
def test_lab03(stdin: str, stdout: str, run_lab) -> None:
    result = run_lab("lab03_loops", stdin)
    assert result.returncode == 0
    assert result.stdout == stdout
    assert result.stderr == ""
