from setuptools import setup, Extension
from Cython.Build import cythonize
from sys import platform


IS_WIN = platform.startswith("win32") or platform.startswith("cygwin")
IS_UNIX = platform.startswith("linux") or platform.startswith("darwin")


compile_args = []  # "-ffast-math", "-march=native",
libraries = []
if IS_WIN:
    compile_args.extend(["/O2", "/openmp"])
    libraries.append("user32")
elif IS_UNIX:
    compile_args.extend(["-O3", "-fopenmp"])


extensions = [
    Extension(
        "g",
        ["inputrack/tracker.pyx", "inputrack/mouse.c"],
        libraries=libraries,
        extra_compile_args=compile_args,
    )
]

setup(
    script_args=["build_ext", "--inplace"],
    ext_modules=cythonize(extensions, force=True),
)
