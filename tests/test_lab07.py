from pathlib import Path

import pytest


@pytest.mark.parametrize(
    ("content", "returncode", "stdout", "output"),
    [
        pytest.param("5\n1 2 3 4 5\n", 0, "", "sum = 15\n", id="basic"),
        pytest.param("0\n", 0, "", "sum = 0\n", id="empty"),
        pytest.param("2\n-5 10\n", 0, "", "sum = 5\n", id="negative"),
        pytest.param("2\n1 2 3 4\n", 0, "", "sum = 3\n", id="extra-values"),
        pytest.param("-1\n", 1, "wrong input\n", None, id="negative-count"),
        pytest.param("2\n1 x\n", 1, "wrong input\n", None, id="bad-value"),
    ],
)
def test_lab07(
    content: str,
    returncode: int,
    stdout: str,
    output: str | None,
    run_lab,
    tmp_path: Path,
) -> None:
    (tmp_path / "input.txt").write_text(content, encoding="utf-8")
    result = run_lab("lab07_files", cwd=tmp_path)
    assert result.returncode == returncode
    assert result.stdout == stdout
    if output is not None:
        assert (tmp_path / "output.txt").read_text(encoding="utf-8") == output


def test_lab07_missing_file(run_lab, tmp_path: Path) -> None:
    result = run_lab("lab07_files", cwd=tmp_path)
    assert result.returncode == 1
    assert result.stdout == "cannot open file\n"
