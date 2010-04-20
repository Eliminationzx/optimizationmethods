#include "mainpassimpl.h"
//
mainPassImpl::mainPassImpl( QWidget * parent, Qt::WFlags f) 
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
	choiceMethods->setCurrentIndex(0);
}
//

//! Нажата кнопка "Ок".
void mainPassImpl::on_Ok_clicked()
{
	// TODO
	QVector<int> flag(2);
	flag[0] = choiceMethods->currentIndex();
	if (Password->text() == "qwerty")
	{
		flag[1] = 1;
		emit setFlag(flag);
		this->close();
	}
}
