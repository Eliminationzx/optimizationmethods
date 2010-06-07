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
	QByteArray data;
	QFile file(QDir::toNativeSeparators("variants/ps"));
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		stream.setCodec("UTF-8");
		data.append(stream.readAll());
	}
	QByteArray passInEdit = QCryptographicHash::hash(Password->text().toUtf8(), QCryptographicHash::Md5);
	
	int flag = choiceMethods->currentIndex();
	if (passInEdit == data)
	{
		emit setFlag(flag, -1);
		this->close();
	}
}
