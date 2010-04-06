#include "mainwindowimpl.h"
//
//! Конструктор класса.
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
	
	takeQuadFun = false;
	
	QVariant var;
	var.setValue(0);
	choiceMethods->addItem(trUtf8("Метод покоординатного спуска с дискретным шагом"), var);
	var.setValue(1);
	choiceMethods->addItem(trUtf8("Метод покоординатного спуска с минимизацией по направлению"), var);
	var.setValue(2);
	choiceMethods->addItem(trUtf8("Метод наискорейшего спуска"), var);
	var.setValue(3);
	choiceMethods->addItem(trUtf8("Метод Хука-Дживса"), var);
	var.setValue(4);
	choiceMethods->addItem(trUtf8("Метод Нелдера-Мида"), var);
	var.setValue(5);
	choiceMethods->addItem(trUtf8("Метод Ньютона"), var);
	choiceMethods->setCurrentIndex(-1);
}
//

//! Нажата кнопка "Далее".
void MainWindowImpl::on_next_button_clicked()
{
	// TODO
	QVector<int> data(2);
	data[0] = choiceMethods->currentIndex();
	if(quadFunction->isChecked())
	{
		data[1] = 0;
	}
	else if(ravinFunction->isChecked() && takeQuadFun)
	{
		data[1] = 1;
	}
	getvariantsImpl getV(data);
	getV.show();
}
