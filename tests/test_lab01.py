import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def test_lab01_creates_files(tmp_path: Path) -> None:
    script = ROOT / "src" / "lab01_linux.sh"
    result = subprocess.run([str(script)], cwd=tmp_path, capture_output=True, text=True)
    assert result.returncode == 0
    assert (tmp_path / "informatics" / "file.txt").read_text(encoding="utf-8") == "hello\nworld\n"
    assert not (tmp_path / "informatics" / "copy.txt").exists()
    assert not (tmp_path / "informatics" / "moved.txt").exists()
    assert "hello\nworld\n" in result.stdout
    assert "done" in result.stdout


def test_lab01_can_run_twice(tmp_path: Path) -> None:
    script = ROOT / "src" / "lab01_linux.sh"
    subprocess.run([str(script)], cwd=tmp_path, check=True, capture_output=True)
    subprocess.run([str(script)], cwd=tmp_path, check=True, capture_output=True)
    assert (tmp_path / "informatics" / "file.txt").read_text(encoding="utf-8") == "hello\nworld\n"


def test_lab01_report_exists() -> None:
    report = ROOT / "src" / "lab01_report.md"
    assert report.is_file()
    text = report.read_text(encoding="utf-8")
    assert "man" in text
    assert "vi" in text
    assert "jobs" in text
    assert "Перенаправление" in text
