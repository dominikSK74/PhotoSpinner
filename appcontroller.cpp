#include "appcontroller.h"


AppController::AppController(QObject *parent)
    : QObject{parent}
{}



void AppController::selectSourceFolder() {
    QString folder = QFileDialog::getExistingDirectory(
        nullptr,
        "Wybierz folder ze zdjęciami",
        QDir::homePath()
        );

    if (!folder.isEmpty()) {

        setSourceFolder(folder);
        changeSourceIcon("qrc:assets/foldercheck.svg"); //TODO
    }
}

void AppController::selectTargetFolder() {
    QString folder = QFileDialog::getExistingDirectory(
        nullptr,
        "Wybierz folder, do którego chcesz przerzucać zdjęcia",
        QDir::homePath()
        );

    if (!folder.isEmpty()) {
        setTargetFolder(folder);
        changeTargetIcon("qrc:assets/foldercheck.svg"); //TODO
    }
}

void AppController::browsePictures() {
    QString src = sourceFolder();
    QString trg = targetFolder();

    qDebug() << src;
    qDebug() << trg;
}


QString AppController::sourceFolder() const { return m_sourceFolder; }

void AppController::setSourceFolder(const QString &folder) {
    if (folder != m_sourceFolder) {
        m_sourceFolder = folder;
        emit sourceFolderChanged();
    }
}

QString AppController::targetFolder() const { return m_targetFolder; }

void AppController::setTargetFolder(const QString &folder) {
    if (folder != m_targetFolder) {
        m_targetFolder = folder;
        emit targetFolderChanged();
    }
}
