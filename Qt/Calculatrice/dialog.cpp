#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->calculer, SIGNAL(clicked()), this, SLOT(calculer()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::calculer()
    {
        int n1 = ui->nombre1->value();
        int n2 = ui->nombre2->value();
        QString resultat;
        if(ui->operation->currentText() == "+")
        {
            ui->resultat->setText(resultat.setNum(n1+n2));
        }
    }
