#ifndef XYENGINEERMANAGEMENT_GLOBAL_H
#define XYENGINEERMANAGEMENT_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef XYENGINEERMANAGEMENT_LIB
# define XYENGINEERMANAGEMENT_EXPORT Q_DECL_EXPORT
#else
# define XYENGINEERMANAGEMENT_EXPORT Q_DECL_IMPORT
#endif

#endif // XYENGINEERMANAGEMENT_GLOBAL_H
