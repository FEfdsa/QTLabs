#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_clear->click();// очищает значения
    ui->lineEdit_Points->setReadOnly(true);//запрещает менять текст
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clear_clicked()
{
    //очищаем места вывода результатов и класса
    ui->label_hp_value->clear();
    ui->label_mp_value->clear();
    ui->label_atk_value->clear();
    ui->label_def_value->clear();
    ui->label_class_value->clear();
    points = 20;//максимум очков
    ui->lineEdit_Points->setText(QString::number(points));//преобразуем число в текст и записываем его в lineEdit
}

void MainWindow::on_pushButton_create_clicked()
{
    QString name;//имя
    int leng;//длина имени
    bool flag;//признак успешности генерации
    int str,agl,intel,luck;//параметры

    name = ui->lineEdit_Name->text();
    leng = name.length();
    if ((leng < 3) ||(leng >20))
    {
        flag = false;
        QMessageBox::warning(this, "Ошибка", "Длина имени должа быть от 3 до 20 симоволов.");
    }
        else
        {
            flag = true;
        }
    if (flag)
    {
        if ((!ui->radioButton_Sex_M->isChecked())&&(!ui->radioButton_Sex_W->isChecked()))
        {
            flag = false;
            QMessageBox::warning(this, "Ошибка", "Пол не выбран.");
        }
            else
            {
                flag = true;
            }
        }
    if (flag) //сила
    {
        str = ui->lineEdit_str->text().toInt(&flag);
        if (!flag)
        {
            QMessageBox::warning(this, "Ошибка", "Не верное значение параметра Сила.");
        }
            else
            {
                if ((str <=1)|| (str >= 10))
                {
                    flag = false;
                    QMessageBox::warning(this, "Ошибка", "Cила должна быть от 1 до 10 включительно.");
                }
            }
    }
    //Самим релизнуть
    if (flag) //ловкость
    {
        agl = ui->lineEdit_agl->text().toInt(&flag);
        if (!flag)
        {
            QMessageBox::warning(this, "Ошибка", "Не верное значение параметра Ловкость.");
        }
            else
            {
                if ((agl <=1)|| (agl >= 10))
                {
                    flag = false;
                    QMessageBox::warning(this, "Ошибка", "Ловкость должна быть от 1 до 10 включительно.");
                }
            }
    }
    if (flag) //интеллект
    {
        intel = ui->lineEdit_int->text().toInt(&flag);
        if (!flag)
        {
            QMessageBox::warning(this, "Ошибка", "Не верное значение параметра Интеллект.");
        }
            else
            {
                if ((intel <=1)|| (intel >= 10))
                {
                    flag = false;
                    QMessageBox::warning(this, "Ошибка", "Интеллект должна быть от 1 до 10 включительно.");
                }
            }
    }
    if (flag) //удача
    {
        luck = ui->lineEdit_luck->text().toInt(&flag);
        if (!flag)
        {
            QMessageBox::warning(this, "Ошибка", "Не верное значение параметра Удача.");
        }
            else
            {
                if ((agl <=1)|| (agl >= 10))
                {
                    flag = false;
                    QMessageBox::warning(this, "Ошибка", "Удача должна быть от 1 до 10 включительно.");
                }
            }
    }

    if (flag)// проверка суммы очков
    {
        int sum= points - (str+agl+intel+luck);
        ui->lineEdit_Points->setText(QString::number(sum));
        if (sum!=0)
        {
            flag = false;//false
            if (sum > 0)
            {
                QMessageBox::warning(this, "Ошибка", "Нужно потратить все очки.");
            }
            else
            {
                QMessageBox::warning(this, "Ошибка", "Нельзя больше чем "+QString::number(points)+" очков." );
            }
        }
    }

    if (flag)// вывод результата
    {
        int hp,mp,atk,def;
        hp = 8*str+2*agl;
        mp = 8*intel+agl+luck;
        atk = 6*str+2*agl+2*luck;
        def = 7*agl+3*luck;


        ui->label_hp_value->setNum(hp);
        ui->label_mp_value->setNum(mp);
        ui->label_hp_value->setNum(atk);
        ui->label_hp_value->setNum(def);
    }
    else
    {
        ui->label_hp_value->clear();
        ui->label_mp_value->clear();
        ui->label_atk_value->clear();
        ui->label_def_value->clear();
        ui->label_class_value->clear();
    }
}
