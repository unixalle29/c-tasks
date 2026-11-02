import pytest


@pytest.mark.parametrize(
    ("stdin", "stdout"),
    [
        pytest.param(
            "n\nAB\033",
            "Show Enter code? (y/n): Enter text, ESC to stop:\n"
            "oct=101 dec=65 hex=41\n"
            "oct=102 dec=66 hex=42\n",
            id="two-chars",
        ),
        pytest.param(
            "n\na\033",
            "Show Enter code? (y/n): Enter text, ESC to stop:\noct=141 dec=97 hex=61\n",
            id="one-char",
        ),
        pytest.param(
            "n\n0\033",
            "Show Enter code? (y/n): Enter text, ESC to stop:\noct=60 dec=48 hex=30\n",
            id="digit",
        ),
        pytest.param(
            "n\n\n\033",
            "Show Enter code? (y/n): Enter text, ESC to stop:\n",
            id="enter-skipped",
        ),
        pytest.param(
            "n\n\033",
            "Show Enter code? (y/n): Enter text, ESC to stop:\n",
            id="esc-only",
        ),
        pytest.param(
            "y\nA\n\033",
            "Show Enter code? (y/n): Enter text, ESC to stop:\n"
            "oct=101 dec=65 hex=41\n"
            "oct=12 dec=10 hex=a\n",
            id="enter-shown",
        ),
    ],
)
def test_lab03(stdin: str, stdout: str, run_lab) -> None:
    result = run_lab("lab03_loops", stdin)
    assert result.returncode == 0
    assert result.stdout == stdout
    assert result.stderr == ""
