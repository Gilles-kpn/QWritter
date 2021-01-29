#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <QObject>
#include <QWidget>
#include <QPlainTextEdit>

class TextArea:public QPlainTextEdit
{
    Q_OBJECT
public:
    TextArea();

private slots:
    void OpenFile();
    void SaveFile();
private:
    bool checkExtension(QFile *f);

    QFile *currentFile = nullptr ;
    const QString fileextension[10] = {"txt","html","css","java","cpp","h","py","php","js","xml"};
};

#endif // TEXTAREA_H
