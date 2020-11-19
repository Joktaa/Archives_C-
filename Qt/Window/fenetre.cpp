#include "fenetre.h"

fenetre::fenetre() : QMainWindow()
{
    QWidget *zoneCentrale = new QWidget;

    QMenu *fichier = menuBar()->addMenu("Fichier");


    QMenu *fichierRecent = fichier->addMenu("fichiers recents");
    fichierRecent->addAction("ebcsubcdsu");

    QAction *quitter = new QAction("Quitter", this);
    fichier->addAction(quitter);

    QToolBar *toolBar = addToolBar("");
    toolBar->addAction(quitter);

    toolBar->addSeparator();

    QFontComboBox *choixPolice = new QFontComboBox;
    toolBar->addWidget(choixPolice);

    QObject::connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    setCentralWidget(zoneCentrale);
}
