#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "OperatorFactory.h"

//using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_factory = nullptr;
}

MainWindow::~MainWindow()
{
    if(m_factory){
        delete m_factory;
        m_factory = nullptr;
    }
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->cb_operator->currentText() == "+"){
        if(m_factory){
            delete m_factory;
        }
        m_factory = new AddFactory;
    }else if(ui->cb_operator->currentText() == "-"){
        if(m_factory){
            delete m_factory;
        }
        m_factory = new SubFactory;
    }else if(ui->cb_operator->currentText() == "*"){
        if(m_factory){
            delete m_factory;
        }
        m_factory = new MulFactory;
    }else if(ui->cb_operator->currentText() == "/"){
        if(m_factory){
            delete m_factory;
        }
        m_factory = new DivFactory;
    }

    Operator* addOpe = m_factory->CreateFactory();
    addOpe->SetNumA(ui->dSp_a->value());
    addOpe->SetNumB(ui->dSp_b->value());
    QT_TRY{
      ui->le_result->setText(QString::number( addOpe->Calculate()));
      delete addOpe;
    }QT_CATCH(Except ex){
         if(ex == EXCEP_ZERO) {
             ui->le_result->setText("除数不能为0");
         };
    }

}

