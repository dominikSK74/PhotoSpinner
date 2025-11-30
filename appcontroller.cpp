#include "appcontroller.h"


AppController::AppController(QObject *parent)
    : QObject{parent}, m_screen("PathSelection.qml"), m_likeIcon("qrc:assets/love.svg")
{}



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

    for (const QString &file : imageFiles) {
        imagePaths << dir.absoluteFilePath(file);
    }

    setScreen("ImageViewer.qml");

    QString filePath = "file:///" + imagePaths[0];
    currentIndex = 0;
    setImagePath(filePath);
    checkIconStatus();
}


QString AppController::sourceFolder() const { return m_sourceFolder; }

void AppController::setSourceFolder(const QString &folder) {
    if (folder != m_sourceFolder) {
        m_sourceFolder = folder;
        emit sourceFolderChanged();
    }
}

int AppController::imgRotation() const { return m_imgRotation; }

void AppController::setImgRotation(const int &imgRotation) {
    if (imgRotation != m_imgRotation) {
        m_imgRotation = imgRotation;
        emit imgRotationChanged();
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
        setRotation();
    }
}

void AppController::rightArrow() {

    if(currentIndex < imagePaths.size()-1){
        currentIndex++;
        QString filePath = "file:///" + imagePaths[currentIndex];
        setImagePath(filePath);
        checkIconStatus();
    }

}

void AppController::leftArrow() {

    if(currentIndex > 0){
        currentIndex--;
        QString filePath = "file:///" + imagePaths[currentIndex];
        setImagePath(filePath);
        checkIconStatus();
    }

}

void AppController::like() {

    QString trg = targetFolder() + "/" + imagePaths[currentIndex].split("/").last();

    if(QFile::exists(trg)) {

        if(!QFile::remove(trg)){
            QMessageBox::warning(nullptr, "Uwaga", "Nie udało się usunąć!");
        }

    }else{
        if(!QFile::copy(imagePaths[currentIndex], trg)) {
            QMessageBox::warning(nullptr, "Uwaga", "Nie udało się skopiować!");
        }
    }

    checkIconStatus();
}

void AppController::checkIconStatus() {
    QString trg = targetFolder() + "/" + imagePaths[currentIndex].split("/").last();
    if(QFile::exists(trg)){
        setLikeIcon("qrc:assets/loveSmile.svg");
    }else {
        setLikeIcon("qrc:assets/love.svg");
    }
}

QString AppController::likeIcon() const { return m_likeIcon; }

void AppController::setLikeIcon(const QString &likeIcon) {
    if (likeIcon != m_likeIcon) {
        m_likeIcon = likeIcon;
        emit likeIconChanged();
    }
}

void AppController::dropToTrash() {
    QFile file(imagePaths[currentIndex]);

    QMessageBox msgBox;
    msgBox.setWindowTitle("Potwierdzenie");
    msgBox.setText("Czy napewno chcesz usunąć to zdjęcie?");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int selectedOption = msgBox.exec();

    if(selectedOption == QMessageBox::Yes) {
        if(!file.moveToTrash()) {
            QMessageBox::warning(nullptr, "Uwaga", "Nie udało się usunąć!");
        }
    }
    refreshPaths();
}

void AppController::refreshPaths() {
    imagePaths.clear();
    QString src = sourceFolder();
    QDir dir(src);

    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png";

    QStringList imageFiles = dir.entryList(filters, QDir::Files);

    for (const QString &file : imageFiles) {
        imagePaths << dir.absoluteFilePath(file);
    }

    if(currentIndex == imagePaths.size()){
        currentIndex--;
    }

    setImagePath("file:///" + imagePaths[currentIndex]);
}

void AppController::setRotation() {
    QImageReader reader(imagePaths[currentIndex]);
    auto t = reader.transformation();
    int angle = 0;

    if (t & QImageIOHandler::TransformationRotate90)  angle = -90;
    else if (t & QImageIOHandler::TransformationRotate180) angle = 180;
    else if (t & QImageIOHandler::TransformationRotate270) angle = 90;
    setImgRotation(angle);
}

void AppController::rotateLeft() {
    setImgRotation(imgRotation() - 90);
}

void AppController::rotateRight() {
    setImgRotation(imgRotation() + 90);
}
