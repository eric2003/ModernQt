#ifndef STATIC_LIB_GLOBAL_H
#define STATIC_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(STATIC_LIB_LIBRARY)
#  define STATIC_LIB_EXPORT Q_DECL_EXPORT
#else
#  define STATIC_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // STATIC_LIB_GLOBAL_H
