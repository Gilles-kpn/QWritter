#include "tab.h"

Tab::Tab()
{
    this->setTabsClosable(true);
    myTextArea = new TextArea();
    this->addTab(myTextArea,"Default");
}
void Tab::createNewTab(){
    TextArea *ta = new TextArea();
    this->addTab(ta,"New Tab");
};
