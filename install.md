1) Create Fortran file, e.g. mymodule.f with a subroutine, e.g. zadd (use lowercasing for compatibility)
2) Compile the Fortran file: gfortran -c mymodule.f -o mymodule.o 
3) Create the C glue code: python -m numpy.f2py -m mymodule mymodule.f
4) Generate the shared library: gcc -shared -fPIC -I$(python3 -c "import numpy; print(numpy.get_include())")     -I$(python3 -c "import numpy.f2py; print(numpy.f2py.get_include())")     $(python3-config --cflags)  mymodulemodule.c mymodule.o $(python3 -c "import numpy.f2py; print(numpy.f2py.get_include())")/fortranobject.c     -lgfortran -o mymodule.so     $(python3-config --ldflags)
