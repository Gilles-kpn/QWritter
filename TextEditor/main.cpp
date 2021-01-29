#include <QApplication>
#include <QtWidgets>
#include <QLayout>
#include "filemanage.h"
#include "textarea.h"
#include "tab.h"



int main(int argc,char* argv[]){
QApplication app(argc,argv);

//******************************Frame
QWidget *frame = new QWidget();
frame->setWindowTitle("TextEditor");
frame->setMinimumSize(800,600);
QVBoxLayout *Vlayout = new QVBoxLayout();
//Menu Bar******************************
QMenuBar *MenuBar = new QMenuBar();

//MenuBar Item**************************
QMenu *File = new QMenu("File");
QMenu *Edit = new QMenu("Edit");
QMenu *View =new QMenu("View");
QMenu *Setting = new QMenu("Settings");

//MenuItem to each Menu*****************

File->addAction("Ouvrir un fichier");
File->addAction("Sauvegarder le fichier");
File->addAction("Quitter");
//********
Edit->addAction("Copier tout le text");
Edit->addAction("Copier");
Edit->addAction("Coller");
Edit->addSeparator();
Edit->addAction("New Tab");
//****
View->addMenu(new QMenu("Change Text Background"));
View->addMenu(new QMenu("Change Text Foreground"));
View->addMenu(new QMenu("Choose the Font"));


//MenuBar add Menu**********************
MenuBar->addMenu(File);
MenuBar->addMenu(Edit);
MenuBar->addMenu(View);
MenuBar->addMenu(Setting);
MenuBar->show();

//TabWidget****************************
Tab *Tabs = new Tab();



//*****************connection
  //QFile connection
   QObject::connect(File->findChildren<QAction *>()[1],SIGNAL(triggered(bool)),qobject_cast<TextArea *>(Tabs->currentWidget()),SLOT(OpenFile()));
   QObject::connect(File->findChildren<QAction *>()[2],SIGNAL(triggered(bool)),qobject_cast<TextArea *>(Tabs->currentWidget()),SLOT(SaveFile()));
   QObject::connect(File->findChildren<QAction *>()[3],SIGNAL(triggered(bool)),&app,SLOT(quit()));

//QEdit connection
   qDebug()<<Edit->findChildren<QAction *>().size();
   QObject::connect(Edit->findChildren<QAction *>()[5],SIGNAL(triggered(bool)),Tabs,SLOT(createNewTab()));


//Root Layout***************************
Vlayout->setMenuBar(MenuBar);
Vlayout->addWidget(Tabs);

//adding root layout*****************
frame->setLayout(Vlayout);
//show Frame**************************
frame->show();
    return app.exec();
}
