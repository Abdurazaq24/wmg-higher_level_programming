#include <Python.h>
#include <bytesobject.h>
#include <listobject.h>
#include <stdio.h>

/**
 * print_python_list - Prints basic information about Python lists
 * @p: PyObject
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t i, size, alloc;
    PyObject *item;

    size = PyList_Size(p);
    alloc = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", alloc);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
    }
}

/**
 * print_python_bytes - Prints Python bytes objects
 * @p: PyObject
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i, limit;
    char *str;

    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    str = PyBytes_AsString(p);

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);

    limit = size + 1;
    if (limit > 10)
        limit = 10;

    printf("  first %ld bytes:", limit);

    for (i = 0; i < limit; i++)
        printf(" %02x", (unsigned char)str[i]);

    printf("\n");
}

