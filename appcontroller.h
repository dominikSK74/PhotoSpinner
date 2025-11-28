#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QStringList>
#include <QMessageBox>
#include <QFile>

class AppController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceFolder READ sourceFolder WRITE setSourceFolder NOTIFY sourceFolderChanged)
    Q_PROPERTY(QString targetFolder READ targetFolder WRITE setTargetFolder NOTIFY targetFolderChanged)
    Q_PROPERTY(QString screen READ screen WRITE setScreen NOTIFY screenChanged)
    Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath NOTIFY imagePathChanged)
    Q_PROPERTY(QString likeIcon READ likeIcon WRITE setLikeIcon NOTIFY likeIconChanged)
    int currentIndex;
    QStringList imagePaths;

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

    QString likeIcon() const;
    void setLikeIcon(const QString &likeIcon);

    void checkIconStatus();
    void refreshPaths();

public slots:
    void selectSourceFolder();
    void selectTargetFolder();
    void browsePictures();
    void rightArrow();
    void leftArrow();
    void like();
    void dropToTrash();

signals:
    void changeSourceIcon(QString iconPath);
    void changeTargetIcon(QString iconPath);

    void sourceFolderChanged();
    void targetFolderChanged();
    void screenChanged();
    void imagePathChanged();
    void likeIconChanged();

private:
    QString m_sourceFolder;
    QString m_targetFolder;
    QString m_screen;
    QString m_imagePath;
    QString m_likeIcon;

};

#endif // APPCONTROLLER_H
