#ifndef HMAPS_CONST_H
#define HMAPS_CONST_H

#if defined(HMAPS_LIBRARY)
#  define HMAPSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HMAPSSHARED_EXPORT Q_DECL_IMPORT
#endif

#define localMapsDir QDir::currentPath() + "/localMap/"
//#define localMapsDir "c:/MapTileDownload/"

//int _getVehicleClientInfo(HMapServerInfoData * pInfo)
//{
//    if (NULL != pInfo) {
//        QString fileName = QDir::currentPath() + "/" + optionFileName;
//        if (QFile::exists(fileName)) {
//            QSettings settings(fileName, QSettings::IniFormat); // 褰撳墠鐩綍鐨処NI鏂囦欢
//            pInfo->port = settings.value("mapServerInfo/port").toInt();
//            pInfo->mapServerDir = settings.value("mapServerInfo/mapServerDir").toString();
//        }
//        else {
//            pInfo->port = 5136;
//            pInfo->mapServerDir = initServerMapDir;
//        }
//    }
//    return 0;
//}

//int _saveVehicleClientInfo(HMapServerInfoData * pInfo)
//{
//    if (NULL != pInfo) {
//        QString fileName = QDir::currentPath() + "/" + optionFileName;
//        QSettings settings(fileName, QSettings::IniFormat);
//        settings.beginGroup("mapServerInfo");
//        settings.setValue("port", pInfo->port);
//        settings.setValue("mapServerDir", pInfo->mapServerDir);
//        settings.endGroup();
//    }
//    return 0;
//}

#endif // HMAPS_CONST_H

