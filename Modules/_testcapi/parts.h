#ifndef Py_TESTCAPI_PARTS_H
#define Py_TESTCAPI_PARTS_H

#include "pyconfig.h"  // for Py_TRACE_REFS

// Figure out if Limited API is available for this build. If it isn't we won't
// build tests for it.
// Currently, only Py_TRACE_REFS disables Limited API.
#ifdef Py_TRACE_REFS
#undef LIMITED_API_AVAILABLE
#else
#define LIMITED_API_AVAILABLE 1
#endif

// Always enable assertions
#undef NDEBUG

#if !defined(LIMITED_API_AVAILABLE) && defined(Py_LIMITED_API)
// Limited API being unavailable means that with Py_LIMITED_API defined
// we can't even include Python.h.
// Do nothing; the .c file that defined Py_LIMITED_API should also do nothing.

#else

#include "Python.h"

int _PyTestCapi_Init_Vectorcall(PyObject *module);
int _PyTestCapi_Init_Heaptype(PyObject *module);
int _PyTestCapi_Init_Unicode(PyObject *module);
int _PyTestCapi_Init_GetArgs(PyObject *module);
int _PyTestCapi_Init_PyTime(PyObject *module);
int _PyTestCapi_Init_DateTime(PyObject *module);

#ifdef LIMITED_API_AVAILABLE
int _PyTestCapi_Init_VectorcallLimited(PyObject *module);
#endif // LIMITED_API_AVAILABLE

#endif
#endif // Py_TESTCAPI_PARTS_H
