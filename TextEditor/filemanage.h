#ifndef FILEMANAGE_H
#define FILEMANAGE_H
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>



class FileManage:public QWidget
{
    Q_OBJECT
public:
    FileManage();
    QString getFileText(QFile *f);

private slots:
    void openFile();
    void SaveFile(QFile *f);

private:
  QFile *activeFile ;
  bool checkExtension(QFile *f);
  QString text;
  const QString fileextension[10] = {"txt","html","css","java","cpp","h","py","php","js","xml"};
};

#endif // FILEMANAGE_H
