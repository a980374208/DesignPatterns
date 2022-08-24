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
    m_theOperator = nullptr;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    OperatorFactory factory(ui->dSp_a->value(),ui->dSp_b->value());
    QT_TRY{
        m_theOperator = factory.CreateOperator(ui->cb_operator->itemText(ui->cb_operator->currentIndex()));
        if(m_theOperator){
            double dResult = m_theOperator->Calculate();
            ui->le_result->setText(QString::number(dResult));
            delete m_theOperator;
        }
    }QT_CATCH(Except ex){
         if(ex == EXCEP_ZERO) {
             ui->le_result->setText("除数不能为0");
         };
    }

}

