/* File: mymodulemodule.c
 * This file is auto-generated with f2py (version:2.1.1).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Wed Sep 11 18:24:42 2024
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif /* PY_SSIZE_T_CLEAN */

/* Unconditionally included */
#include <Python.h>
#include <numpy/npy_os.h>

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "fortranobject.h"
/*need_includes0*/

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *mymodule_error;
static PyObject *mymodule_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
typedef struct {double r,i;} complex_double;

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/

#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif


/* See fortranobject.h for definitions. The macros here are provided for BC. */
#define rank f2py_rank
#define shape f2py_shape
#define fshape f2py_shape
#define len f2py_len
#define flen f2py_flen
#define slen f2py_slen
#define size f2py_size


#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
    PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
    fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif


#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/

static int
int_from_pyobj(int* v, PyObject *obj, const char *errmess)
{
    PyObject* tmp = NULL;

    if (PyLong_Check(obj)) {
        *v = Npy__PyLong_AsInt(obj);
        return !(*v == -1 && PyErr_Occurred());
    }

    tmp = PyNumber_Long(obj);
    if (tmp) {
        *v = Npy__PyLong_AsInt(tmp);
        Py_DECREF(tmp);
        return !(*v == -1 && PyErr_Occurred());
    }

    if (PyComplex_Check(obj)) {
        PyErr_Clear();
        tmp = PyObject_GetAttrString(obj,"real");
    }
    else if (PyBytes_Check(obj) || PyUnicode_Check(obj)) {
        /*pass*/;
    }
    else if (PySequence_Check(obj)) {
        PyErr_Clear();
        tmp = PySequence_GetItem(obj, 0);
    }

    if (tmp) {
        if (int_from_pyobj(v, tmp, errmess)) {
            Py_DECREF(tmp);
            return 1;
        }
        Py_DECREF(tmp);
    }

    {
        PyObject* err = PyErr_Occurred();
        if (err == NULL) {
            err = mymodule_error;
        }
        PyErr_SetString(err, errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(zadd,ZADD)(complex_double*,complex_double*,complex_double*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/************************************ zadd ************************************/
static char doc_f2py_rout_mymodule_zadd[] = "\
zadd(A,B,C,N)\n\nWrapper for ``zadd``.\
\n\nParameters\n----------\n"
"A : input rank-1 array('D') with bounds (*)\n"
"B : input rank-1 array('D') with bounds (*)\n"
"C : input rank-1 array('D') with bounds (*)\n"
"N : input int";
/* extern void F_FUNC(zadd,ZADD)(complex_double*,complex_double*,complex_double*,int*); */
static PyObject *f2py_rout_mymodule_zadd(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(complex_double*,complex_double*,complex_double*,int*)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    complex_double *A = NULL;
    npy_intp A_Dims[1] = {-1};
    const int A_Rank = 1;
    PyArrayObject *capi_A_as_array = NULL;
    int capi_A_intent = 0;
    PyObject *A_capi = Py_None;
    complex_double *B = NULL;
    npy_intp B_Dims[1] = {-1};
    const int B_Rank = 1;
    PyArrayObject *capi_B_as_array = NULL;
    int capi_B_intent = 0;
    PyObject *B_capi = Py_None;
    complex_double *C = NULL;
    npy_intp C_Dims[1] = {-1};
    const int C_Rank = 1;
    PyArrayObject *capi_C_as_array = NULL;
    int capi_C_intent = 0;
    PyObject *C_capi = Py_None;
    int N = 0;
    PyObject *N_capi = Py_None;
    static char *capi_kwlist[] = {"A","B","C","N",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "OOOO|:mymodule.zadd",\
        capi_kwlist,&A_capi,&B_capi,&C_capi,&N_capi))
        return NULL;
/*frompyobj*/
    /* Processing variable A */
    ;
    capi_A_intent |= F2PY_INTENT_IN;
    const char * capi_errmess = "mymodule.mymodule.zadd: failed to create array from the 1st argument `A`";
    capi_A_as_array = ndarray_from_pyobj(  NPY_CDOUBLE,1,A_Dims,A_Rank,  capi_A_intent,A_capi,capi_errmess);
    if (capi_A_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = mymodule_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        A = (complex_double *)(PyArray_DATA(capi_A_as_array));

    /* Processing variable B */
    ;
    capi_B_intent |= F2PY_INTENT_IN;
    const char * capi_errmess = "mymodule.mymodule.zadd: failed to create array from the 2nd argument `B`";
    capi_B_as_array = ndarray_from_pyobj(  NPY_CDOUBLE,1,B_Dims,B_Rank,  capi_B_intent,B_capi,capi_errmess);
    if (capi_B_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = mymodule_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        B = (complex_double *)(PyArray_DATA(capi_B_as_array));

    /* Processing variable C */
    ;
    capi_C_intent |= F2PY_INTENT_IN;
    const char * capi_errmess = "mymodule.mymodule.zadd: failed to create array from the 3rd argument `C`";
    capi_C_as_array = ndarray_from_pyobj(  NPY_CDOUBLE,1,C_Dims,C_Rank,  capi_C_intent,C_capi,capi_errmess);
    if (capi_C_as_array == NULL) {
        PyObject* capi_err = PyErr_Occurred();
        if (capi_err == NULL) {
            capi_err = mymodule_error;
            PyErr_SetString(capi_err, capi_errmess);
        }
    } else {
        C = (complex_double *)(PyArray_DATA(capi_C_as_array));

    /* Processing variable N */
        f2py_success = int_from_pyobj(&N,N_capi,"mymodule.zadd() 4th argument (N) can't be converted to int");
    if (f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)(A,B,C,&N);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
    } /*if (f2py_success) of N*/
    /* End of cleaning variable N */
    if((PyObject *)capi_C_as_array!=C_capi) {
        Py_XDECREF(capi_C_as_array); }
    }  /* if (capi_C_as_array == NULL) ... else of C */
    /* End of cleaning variable C */
    if((PyObject *)capi_B_as_array!=B_capi) {
        Py_XDECREF(capi_B_as_array); }
    }  /* if (capi_B_as_array == NULL) ... else of B */
    /* End of cleaning variable B */
    if((PyObject *)capi_A_as_array!=A_capi) {
        Py_XDECREF(capi_A_as_array); }
    }  /* if (capi_A_as_array == NULL) ... else of A */
    /* End of cleaning variable A */
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************** end of zadd ********************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
    {"zadd",-1,{{-1}},0,0,(char *)  F_FUNC(zadd,ZADD),  (f2py_init_func)f2py_rout_mymodule_zadd,doc_f2py_rout_mymodule_zadd},

/*eof routine_defs*/
    {NULL}
};

static PyMethodDef f2py_module_methods[] = {

    {NULL,NULL}
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "mymodule",
    NULL,
    -1,
    f2py_module_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_mymodule(void) {
    int i;
    PyObject *m,*d, *s, *tmp;
    m = mymodule_module = PyModule_Create(&moduledef);
    Py_SET_TYPE(&PyFortran_Type, &PyType_Type);
    import_array();
    if (PyErr_Occurred())
        {PyErr_SetString(PyExc_ImportError, "can't initialize module mymodule (failed to import numpy)"); return m;}
    d = PyModule_GetDict(m);
    s = PyUnicode_FromString("2.1.1");
    PyDict_SetItemString(d, "__version__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString(
        "This module 'mymodule' is auto-generated with f2py (version:2.1.1).\nFunctions:\n"
"    zadd(A,B,C,N)\n"
".");
    PyDict_SetItemString(d, "__doc__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString("2.1.1");
    PyDict_SetItemString(d, "__f2py_numpy_version__", s);
    Py_DECREF(s);
    mymodule_error = PyErr_NewException ("mymodule.error", NULL, NULL);
    /*
     * Store the error object inside the dict, so that it could get deallocated.
     * (in practice, this is a module, so it likely will not and cannot.)
     */
    PyDict_SetItemString(d, "_mymodule_error", mymodule_error);
    Py_DECREF(mymodule_error);
    for(i=0;f2py_routine_defs[i].name!=NULL;i++) {
        tmp = PyFortranObject_NewAsAttr(&f2py_routine_defs[i]);
        PyDict_SetItemString(d, f2py_routine_defs[i].name, tmp);
        Py_DECREF(tmp);
    }

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#if Py_GIL_DISABLED
    // signal whether this module supports running with the GIL disabled
    PyUnstable_Module_SetGIL(m , Py_MOD_GIL_USED);
#endif

#ifdef F2PY_REPORT_ATEXIT
    if (! PyErr_Occurred())
        on_exit(f2py_report_on_exit,(void*)"mymodule");
#endif
    return m;
}
#ifdef __cplusplus
}
#endif
