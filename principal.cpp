#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->inCent,SIGNAL(valueChanged(int)), this, SLOT(cent2fha(int)));
    connect(ui->inCent,SIGNAL(valueChanged(int)), this, SLOT(cent2kel(int)));
    connect(ui->inFar, SIGNAL(valueChanged(int)), this, SLOT(fha2cent(int)));
    connect(ui->inFar, SIGNAL(valueChanged(int)), this, SLOT(fha2kel(int)));
    connect(ui->inKel,SIGNAL(valueChanged(int)),this,SLOT(kel2cent(int)));
    connect(ui->inKel,SIGNAL(valueChanged(int)),this,SLOT(kel2fha(int)));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fha(int cent)
{
    if(ui->inCent->hasFocus()){
            int f = (cent * 9.0/5) + 32;
            ui->inFar->setValue(f);
    }
}

void Principal::cent2kel(int i)
{
    if(ui->inCent->hasFocus()){
            int k = i + 273;
            ui->inKel->setValue(k); //Actualiza el valor al dial de kelvin
    }
}

void Principal::fha2cent(int i)
{
    if(ui->inFar->hasFocus()){
            int c = (i-32) * 5.0/9;
            ui->inCent->setValue(c);
    }
}

void Principal::fha2kel(int i)
{
    if(ui->inFar->hasFocus()){
            int k = (i+459) * (5.0/9);
            ui->inKel->setValue(k);
    }
}

void Principal::kel2cent(int i)
{
    if(ui->inKel->hasFocus()){
            int c = i-273;
            ui->inCent->setValue(c);
    }
}

void Principal::kel2fha(int i)
{
    if(ui->inKel->hasFocus()){
            int f = (i - 273) * 1.8 +32;
            ui->inFar->setValue(f);
        }
}


