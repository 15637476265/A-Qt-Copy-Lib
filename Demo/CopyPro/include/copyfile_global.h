#ifndef COPYFILE_GLOBAL_H
#define COPYFILE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COPYFILE_LIBRARY)
#  define COPYFILESHARED_EXPORT Q_DECL_EXPORT
#else
#  define COPYFILESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // COPYFILE_GLOBAL_H
