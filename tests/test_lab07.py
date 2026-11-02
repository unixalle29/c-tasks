from pathlib import Path

import pytest

VALID_INPUT = """3 4
1 2 3 4
5 6 7 8
9 10 11 12
4 2
1 2
3 4
5 6
7 8
"""

VALID_OUTPUT = """multiply: 0
C:
   50.00   60.00
  114.00  140.00
  178.00  220.00
closest: row=2 col=1 value=114.00
NULL: 1
error: NULL pointer
Wrong size: 2
error: wrong dimensions
Other size: 0
"""

VALID_FILE = """   50.00   60.00
  114.00  140.00
  178.00  220.00
"""


def test_lab07_valid(tmp_path: Path, run_lab) -> None:
    (tmp_path / "input.txt").write_text(VALID_INPUT, encoding="utf-8")
    result = run_lab("lab07_files", cwd=tmp_path)
    assert result.returncode == 0
    assert result.stdout == VALID_OUTPUT
    assert (tmp_path / "output.txt").read_text(encoding="utf-8") == VALID_FILE


def test_lab07_one_by_one(tmp_path: Path, run_lab) -> None:
    (tmp_path / "input.txt").write_text("1 1\n5\n1 1\n3\n", encoding="utf-8")
    result = run_lab("lab07_files", cwd=tmp_path)
    assert result.returncode == 0
    assert "multiply: 0" in result.stdout
    assert "   15.00" in result.stdout
    assert "closest: row=1 col=1 value=15.00" in result.stdout
    assert (tmp_path / "output.txt").read_text(encoding="utf-8") == "   15.00\n"


def test_lab07_dimension_mismatch(tmp_path: Path, run_lab) -> None:
    (tmp_path / "input.txt").write_text("2 3\n1 2 3\n4 5 6\n2 2\n1 2\n3 4\n", encoding="utf-8")
    result = run_lab("lab07_files", cwd=tmp_path)
    assert result.returncode == 2
    assert result.stdout == "multiply: 2\nerror: wrong dimensions\n"
    assert not (tmp_path / "output.txt").exists()


def test_lab07_missing_file(tmp_path: Path, run_lab) -> None:
    result = run_lab("lab07_files", cwd=tmp_path)
    assert result.returncode == 1
    assert result.stdout == "cannot open input.txt\n"


@pytest.mark.parametrize(
    "content",
    ["", "3 4\n1 2 3\n", "0 1\n1\n", "abc\n", "1 1\n5\n1 1\nx\n"],
)
def test_lab07_invalid_input(tmp_path: Path, run_lab, content: str) -> None:
    (tmp_path / "input.txt").write_text(content, encoding="utf-8")
    result = run_lab("lab07_files", cwd=tmp_path)
    assert result.returncode == 1
    assert result.stdout in {"invalid input.txt\n", "invalid dimensions\n"}
