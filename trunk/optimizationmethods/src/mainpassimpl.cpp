#include "mainpassimpl.h"
//
mainPassImpl::mainPassImpl(int method, QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	
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
	
	choiceMethods->setCurrentIndex(method);
}
//

//! Нажата кнопка "Ок".
void mainPassImpl::on_Ok_clicked()
{
	// TODO
	int flag = choiceMethods->currentIndex();
	if (Password->text() == "qwerty")
	{
		emit setFlag(flag);
		this->close();
	}
}
