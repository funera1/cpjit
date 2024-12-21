# https://github.com/python/cpython/blob/main/Tools/jit/_targets.py
import pathlib

def compile(
    opname: str, c: pathlib.Path, tempdir: pathlib.Path
):
    o = tempdir / f"{opname}".o
    args = [
        f"--target=x86_64",
        f"-D_JIT_OPCODE={opname}",
        "-O3",
        "-c",
        "-fno-asynchronous-unwind-tables",
        "-fno-builtin",
        "-fno-plt",
        "-fno-stack-protector",
        "-std=c11"
    ]
