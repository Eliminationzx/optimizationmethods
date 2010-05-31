#include "algoritmowin.h"
#include "funkcio.h"
#include "mapoporfunkcioimpl.h"
//
AlgoritmoWin::AlgoritmoWin( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WindowFlags flags ) 
	: QMainWindow(parent, flags), F(f), D(*d),
		MapoWdg(new MapoPorFunkcioImpl(f, this)), strikteco((*d)[0]) {}
//

QString AlgoritmoWin::textoFunkcio(){
	QString formulo = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
		"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">"
		"p, li { white-space: pre-wrap; }"
		"</style></head><body style=\" font-family:'Times New Roman'; font-size:16pt; font-weight:400; font-style:normal;\">"
		"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f(X)=";
	if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		if (F->getA()){
			if (F->getA() != 1){
				formulo += trUtf8("%1*").arg(F->getA());
			}
			if (F->getB()){
				formulo += "(";
			}
			formulo += "x<span style=\" vertical-align:sub;\">1</span>";
			if (F->getB()){
				if (F->getB() < 0) formulo += trUtf8(" + %1)").arg(-F->getB());
				else formulo += trUtf8(" - %1)").arg(F->getB());
			}
			formulo += "<span style=\" vertical-align:super;\">2</span>";
		}
		if (F->getC()){
			if (F->getC() != 1){
				if (F->getC() < 0)formulo += trUtf8(" - %1*").arg(-F->getC());
				else formulo += trUtf8(" + %1*").arg(F->getC());
			}
			if (F->getD()){
				formulo += "(";
			}
			formulo += "x<span style=\" vertical-align:sub;\">2</span>";
			if (F->getD()){
				if (F->getD() < 0) formulo += trUtf8(" + %1)").arg(-F->getD());
				else formulo += trUtf8(" - %1)").arg(F->getD());
			}
			formulo += "<span style=\" vertical-align:super;\">2</span>";
		}
		if (F->getE()){
			if (F->getE()!=1){
				if (F->getE() < 0) formulo += trUtf8(" - %1*").arg(-F->getE());
				else formulo += trUtf8(" + %1*").arg(F->getE());
			}
			if (F->getF()){
				formulo += " (";
			}
			formulo += "x<span style=\" vertical-align:sub;\">1</span>";
			if (F->getF()){
				if (F->getF() < 0)formulo += trUtf8(" + %1) ").arg(-F->getF());
				else formulo += trUtf8(" - %1) ").arg(F->getF());
			}
			formulo += "*";
			if (F->getG()){
				formulo += " (";
			}
			formulo += "x<span style=\" vertical-align:sub;\">2</span>";
			if (F->getG()){
				if (F->getG() < 0)formulo += trUtf8(" + %1) ").arg(-F->getG());
				else formulo += trUtf8(" - %1) ").arg(F->getG());
			}
		}
	else if(F->metaObject()->className() == QString("RavinaFunkcio")){
		if (F->getA()){
			if (F->getA()!=1){
				formulo += trUtf8("%1*").arg(F->getA());
			}
			formulo += "(x<span style=\" vertical-align:sub;\">2</span>"
			           " - x<span style=\" vertical-align:sub;\">1</span>)"
			           "<span style=\" vertical-align:super;\">2</span>";
		}
		if (F->getB()){
			if (F->getB()!=1){
				if (F->getB() < 0) formulo += trUtf8(" - %1)").arg(-F->getB());
				else formulo += trUtf8(" + %1)").arg(F->getB());
			}
			formulo += "(1 - x<span style=\" vertical-align:sub;\">1</span>)"
			           "<span style=\" vertical-align:super;\">2</span>";
		}
	}
	formulo += "</p></body></html>";
	return formulo;
}
