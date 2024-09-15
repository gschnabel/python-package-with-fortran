from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext as build_ext_orig
import numpy
import subprocess
import os
import shutil
import sysconfig
import sys


class build_ext(build_ext_orig):
    def run(self):
        # Compile the Fortran code
        if sys.platform != 'win32':
            subprocess.check_call(['gfortran', '-c', 'python_package_with_fortran/mymodule.f', '-o', 'python_package_with_fortran/mymodule.o'])
        else:
            subprocess.check_call(['ifx', '/c', 'python_package_with_fortran/mymodule.f', '/Fopython_package_with_fortran/mymodule.o'])
        # Call the original build_ext
        super().run()

        # build_lib_dir = os.path.join(self.build_lib, 'python_package_with_fortran')
        # shared_lib = self.get_ext_fullpath('mymodule')
        # target_dir = 'python_package_with_fortran'
        # shutil.move(shared_lib, os.path.join(build_lib_dir, 'mymodule.so' ))
        lib_ext = sysconfig.get_config_var('EXT_SUFFIX')
        build_lib_dir = os.path.join(self.build_lib, 'python_package_with_fortran')
        shared_lib_name = 'mymodule' + lib_ext 
        shared_lib_src = self.get_ext_fullpath('mymodule') 
        shared_lib_dst = os.path.join(build_lib_dir, shared_lib_name)
        print('###################')
        print(build_lib_dir)
        print(shared_lib_src)
        print(shared_lib_dst)
        # Move the shared library to the correct location
        if os.path.exists(shared_lib_src):
            shutil.move(shared_lib_src, shared_lib_dst)
        else:
            raise Exception("not working")
            print(f"Warning: Shared library {shared_lib_src} not found")


f2py_include_path = numpy.f2py.get_include()
fortranobject_c_path = os.path.join(f2py_include_path, 'fortranobject.c')


# Define the extension module
if sys.platform != 'win32':
    add_libraries = ['gfortran']
    c_module_file = 'mymodulemodule_other.c'
else:
    add_libraries = []
    c_module_file = 'mymodulemodule_win32.c'

extension = Extension(
    'mymodule',
    sources=[
        fortranobject_c_path,
        f'python_package_with_fortran/{c_module_file}',  # Use the correct file generated by numpy.f2py
    ],
    extra_objects=[
        'python_package_with_fortran/mymodule.o'
    ],
    include_dirs=[
        numpy.get_include(),
        numpy.f2py.get_include(),
    ],
    libraries=add_libraries,
)

setup(
    name='python_package_with_fortran',
    version='1.0',
    packages=['python_package_with_fortran'],
    ext_modules=[extension],
    cmdclass={'build_ext': build_ext},
    install_requires=[
        'numpy'
    ],
    description='A package with Fortran code exposed to Python',
    long_description=open('README.md').read(),
    long_description_content_type='text/markdown',
    classifiers=[
        'Programming Language :: Python :: 3',
        'Programming Language :: Fortran',
        'Programming Language :: C',
        'Operating System :: OS Independent',
    ],
)
