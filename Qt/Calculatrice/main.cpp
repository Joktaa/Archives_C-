#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Dialog fenetre;
    fenetre.show();

    return app.exec();
}
