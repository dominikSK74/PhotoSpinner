#include "appcontroller.h"


AppController::AppController(QObject *parent)
    : QObject{parent}, m_screen("PathSelection.qml")
{
    setScreen("ImageViewer.qml");
    setImagePath("file:///C:\\Users\\domin\\Desktop\\folder1\\pies.jpg");
}



void AppController::selectSourceFolder() {
    QString folder = QFileDialog::getExistingDirectory(
        nullptr,
        "Wybierz folder ze zdjęciami",
        QDir::homePath()
        );

    if (!folder.isEmpty()) {

        setSourceFolder(folder);
        changeSourceIcon("qrc:assets/foldercheck.svg");
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
        changeTargetIcon("qrc:assets/foldercheck.svg");
    }
}

void AppController::browsePictures() {
    QString src = sourceFolder();
    QString trg = targetFolder();

    if(src.isEmpty() || trg.isEmpty()){
        QMessageBox::warning(nullptr, "Uwaga", "Nie podano poprawnych ścieżek do folderów!");
        return;
    }

    if(!QDir(src).exists() || !QDir(trg).exists()){
        QMessageBox::warning(nullptr, "Uwaga", "Nie podano poprawnych ścieżek do folderów!");
        return;
    }



    QDir dir(src);

    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png";

    QStringList imageFiles = dir.entryList(filters, QDir::Files);
    QStringList imagePaths;

    for (const QString &file : imageFiles) {
        imagePaths << dir.absoluteFilePath(file);
    }

    for(const QString &file : imagePaths) {
        qDebug() << file;
    }

    setScreen("ImageViewer.qml");

    QString filePath = "file:///" + imagePaths[0];
    qDebug() << filePath;

    setImagePath(filePath);
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

QString AppController::screen() const {
    return m_screen;
}

void AppController::setScreen(const QString &screenFile){
    if(screenFile != m_screen){
        m_screen = screenFile;
        emit screenChanged();
    }
}

QString AppController::imagePath() const { return m_imagePath; }
void AppController::setImagePath(const QString &imagePath) {
    if(imagePath != m_imagePath){
        m_imagePath = imagePath;
        emit imagePathChanged();
    }
}
