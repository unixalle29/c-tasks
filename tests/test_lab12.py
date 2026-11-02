import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EXPECTED = "value = 5\nsquare = 25\nmax = 7\n"


def test_lab12(run_lab) -> None:
    result = run_lab("lab12_preprocessor")
    assert result.returncode == 0
    assert result.stdout == EXPECTED
    assert result.stderr == ""


def test_lab12_debug_compile(tmp_path: Path) -> None:
    binary = tmp_path / "lab12_debug"
    source = ROOT / "src" / "lab12_preprocessor.c"
    subprocess.run(
        ["cc", "-std=c11", "-Wall", "-Wextra", "-DDEBUG", str(source), "-o", str(binary)],
        check=True,
    )
    result = subprocess.run([str(binary)], capture_output=True, text=True)
    assert result.returncode == 0
    assert "debug: " in result.stdout
