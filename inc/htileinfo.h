#ifndef HTILEINFO_H
#define HTILEINFO_H

#include <QImage>

class HTileInfo
{
public:
    explicit HTileInfo(const QString& fileName);
    virtual ~HTileInfo();
    QImage* getImage() const;

private:
    void clearImage();

private:
    QImage          * m_pImage;
};

#endif // HTILEINFO_H
