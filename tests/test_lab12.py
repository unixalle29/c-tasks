import subprocess
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]


@pytest.mark.parametrize(
    ("stdin", "returncode", "stdout"),
    [
        pytest.param(
            "3\n1\n2\n4\n",
            0,
            "Count: Value: Value: Value: Harmonic mean = 1.714286\n",
            id="three-values",
        ),
        pytest.param(
            "1\n5\n",
            0,
            "Count: Value: Harmonic mean = 5.000000\n",
            id="one-value",
        ),
        pytest.param(
            "2\n2\n4\n",
            0,
            "Count: Value: Value: Harmonic mean = 2.666667\n",
            id="two-values",
        ),
        pytest.param("0\n", 1, "Count: invalid count\n", id="zero-count"),
        pytest.param("-1\n", 1, "Count: invalid count\n", id="negative-count"),
        pytest.param("3\n0\n", 1, "Count: Value: invalid value\n", id="zero-value"),
        pytest.param("2\n1\n-2\n", 1, "Count: Value: Value: invalid value\n", id="negative-value"),
        pytest.param("abc\n", 1, "Count: invalid count\n", id="bad-count"),
    ],
)
def test_lab12(stdin: str, returncode: int, stdout: str, run_lab) -> None:
    result = run_lab("lab12_preprocessor", stdin)
    assert result.returncode == returncode
    assert result.stdout == stdout
    assert result.stderr == ""


def test_lab12_header_include_guard(tmp_path: Path) -> None:
    source = tmp_path / "main.c"
    binary = tmp_path / "main"
    source.write_text(
        '#include "harmonic.h"\n#include "harmonic.h"\nint main(void) { return 0; }\n',
        encoding="utf-8",
    )
    subprocess.run(
        [
            "cc",
            "-std=c11",
            "-Wall",
            "-Wextra",
            "-I",
            str(ROOT / "src"),
            str(source),
            "-o",
            str(binary),
        ],
        check=True,
    )
    assert subprocess.run([str(binary)], check=False).returncode == 0
