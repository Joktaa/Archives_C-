#include "fenetre.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    fenetre fenetre;
    fenetre.show();

    return app.exec();
}
