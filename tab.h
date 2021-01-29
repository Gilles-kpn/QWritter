#ifndef TAB_H
#define TAB_H

#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include "textarea.h"

class Tab:public QTabWidget
{
    Q_OBJECT
public:
    Tab();
private slots:
    void createNewTab();
private:
    TextArea *myTextArea ;
};

#endif // TAB_H
