#ifndef XYINTELLIGENTMONITOR_GLOBAL_H
#define XYINTELLIGENTMONITOR_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef XYINTELLIGENTMONITOR_LIB
# define XYINTELLIGENTMONITOR_EXPORT Q_DECL_EXPORT
#else
# define XYINTELLIGENTMONITOR_EXPORT Q_DECL_IMPORT
#endif

#endif // XYINTELLIGENTMONITOR_GLOBAL_H
