import subprocess
from collections.abc import Callable
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"


@pytest.fixture(scope="session", autouse=True)
def build_programs() -> None:
    subprocess.run(["make"], cwd=ROOT, check=True)


@pytest.fixture
def run_lab() -> Callable[..., subprocess.CompletedProcess[str]]:
    def run(
        name: str,
        stdin: str = "",
        cwd: Path | None = None,
    ) -> subprocess.CompletedProcess[str]:
        return subprocess.run(
            [str(BUILD / name)],
            input=stdin,
            capture_output=True,
            text=True,
            cwd=cwd or ROOT,
            check=False,
        )

    return run
