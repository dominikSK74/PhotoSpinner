#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QFileDialog>

class AppController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceFolder READ sourceFolder WRITE setSourceFolder NOTIFY sourceFolderChanged)
    Q_PROPERTY(QString targetFolder READ targetFolder WRITE setTargetFolder NOTIFY targetFolderChanged)

public:
    explicit AppController(QObject *parent = nullptr);

    QString sourceFolder() const;
    void setSourceFolder(const QString &folder);

    QString targetFolder() const;
    void setTargetFolder(const QString &folder);

public slots:
    void selectSourceFolder();
    void selectTargetFolder();
    void browsePictures();
signals:
    void changeSourceIcon(QString iconPath);
    void changeTargetIcon(QString iconPath);

    void sourceFolderChanged();
    void targetFolderChanged();

private:
    QString m_sourceFolder;
    QString m_targetFolder;

};

#endif // APPCONTROLLER_H
