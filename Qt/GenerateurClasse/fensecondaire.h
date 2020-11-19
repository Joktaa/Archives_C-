#ifndef FENSECONDAIRE_H
#define FENSECONDAIRE_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

class FenSecondaire : public QDialog
{
private :
//Layout
    QVBoxLayout *mainLayout;

//Widgets
    QTextEdit *classe;
    QPushButton *quitter;
    QString m_texte;


public :
    FenSecondaire(QString texte);

};

#endif // FENSECONDAIRE_H
