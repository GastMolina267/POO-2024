#ifndef LIBRARY_H
#define LIBRARY_H

#ifdef _WIN32
#define LIBRARY_EXPORT __declspec(dllexport)
#else
#define LIBRARY_EXPORT
#endif

extern "C" LIBRARY_EXPORT void sayHello();

#endif // LIBRARY_H
