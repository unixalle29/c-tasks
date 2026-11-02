import pytest


@pytest.mark.parametrize(
    ("stdin", "stdout"),
    [
        pytest.param(
            "Hello\nworld\n.\n",
            "Enter words, finish with a period:\nSentence: Hello world\n",
            id="two-words",
        ),
        pytest.param(
            "One line.\n",
            "Enter words, finish with a period:\nSentence: One line\n",
            id="period-in-line",
        ),
        pytest.param(".\n", "Enter words, finish with a period:\nSentence: \n", id="empty"),
        pytest.param(
            "Hello\nworld",
            "Enter words, finish with a period:\nSentence: Hello world\n",
            id="eof-without-period",
        ),
        pytest.param(
            "Hello. ignore this\n",
            "Enter words, finish with a period:\nSentence: Hello\n",
            id="ignore-after-period",
        ),
        pytest.param("", "Enter words, finish with a period:\nSentence: \n", id="no-input"),
    ],
)
def test_lab05(stdin: str, stdout: str, run_lab) -> None:
    result = run_lab("lab05_strings", stdin)
    assert result.returncode == 0
    assert result.stdout == stdout
    assert result.stderr == ""
