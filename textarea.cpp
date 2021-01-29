#include "textarea.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

TextArea::TextArea()
{
}

void TextArea::OpenFile(){
    QString fileurl = QFileDialog::getOpenFileName(this,"Choose one  files", "", "*");
    if(fileurl.length()!=0){
    QFile *activeFile = new QFile(fileurl);
    if(checkExtension(activeFile)){
        qDebug()<<"valid extension";
        currentFile = activeFile;
        currentFile->open(QFile::ReadOnly|QFile::Text);
        QTextStream line(currentFile);
        this->setPlainText("");
        while(!line.atEnd()){
            this->setPlainText(this->toPlainText()+line.readLine()+"\n");
            //qDebug()<<line.readLine();
        }
        currentFile->close();

    }else{
        QMessageBox::critical(this,"Cannot read File","Extension non valide");
        }
    }
}

void TextArea::SaveFile(){
    if(!currentFile){
        qDebug()<<"Null file";
        currentFile = new QFile(QFileDialog::getSaveFileName(this,"Sauvegarder le fichier"));
        SaveFile();
    }else{
        qDebug()<<"Not Null file";
        currentFile->open(QFile::ReadWrite|QFile::Text);
        currentFile->write(this->toPlainText().toUtf8());
        currentFile->close();
    }

}
bool TextArea::checkExtension(QFile *f){
    for(QString ext:fileextension){
        if(f->fileName().endsWith(ext)){
            return true;
        }
    }
    return false;
}
