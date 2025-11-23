#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QStringList>
#include <QMessageBox>

class AppController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceFolder READ sourceFolder WRITE setSourceFolder NOTIFY sourceFolderChanged)
    Q_PROPERTY(QString targetFolder READ targetFolder WRITE setTargetFolder NOTIFY targetFolderChanged)
    Q_PROPERTY(QString screen READ screen WRITE setScreen NOTIFY screenChanged)
    Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath NOTIFY imagePathChanged)

public:
    explicit AppController(QObject *parent = nullptr);

    QString sourceFolder() const;
    void setSourceFolder(const QString &folder);

    QString targetFolder() const;
    void setTargetFolder(const QString &folder);

    QString screen() const;
    void setScreen(const QString &screenFile);

    QString imagePath() const;
    void setImagePath(const QString &imagePath);

public slots:
    void selectSourceFolder();
    void selectTargetFolder();
    void browsePictures();
signals:
    void changeSourceIcon(QString iconPath);
    void changeTargetIcon(QString iconPath);

    void sourceFolderChanged();
    void targetFolderChanged();
    void screenChanged();
    void imagePathChanged();

private:
    QString m_sourceFolder;
    QString m_targetFolder;
    QString m_screen;
    QString m_imagePath;

};

#endif // APPCONTROLLER_H
