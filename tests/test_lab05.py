import pytest


@pytest.mark.parametrize(
    ("stdin", "stdout"),
    [
        pytest.param("hello\n", "Text: Reverse: olleh\n", id="basic"),
        pytest.param("\n", "Text: Reverse: \n", id="empty"),
        pytest.param("a\n", "Text: Reverse: a\n", id="one-char"),
        pytest.param("abc", "Text: Reverse: cba\n", id="no-newline"),
        pytest.param("12345\n", "Text: Reverse: 54321\n", id="digits"),
    ],
)
def test_lab05(stdin: str, stdout: str, run_lab) -> None:
    result = run_lab("lab05_strings", stdin)
    assert result.returncode == 0
    assert result.stdout == stdout
    assert result.stderr == ""
