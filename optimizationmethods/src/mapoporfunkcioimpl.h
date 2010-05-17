#ifndef MAPOPORFUNKCIOIMPL_H
#define MAPOPORFUNKCIOIMPL_H
//
#include <QWidget>
#include "ui_mapoporfunkcio.h"
#include "Konstantoj.h"
//
class ScenoPorMapo;
class QGraphicsItem;
class funkcio;
class spuro;
//
using namespace std;
//! Виджет для отображения карты высот целевой функции и "следа алгоритма на ней"
class MapoPorFunkcioImpl : public QWidget, public Ui::MapoPorFunkcio
{
Q_OBJECT
Q_PROPERTY(qreal skalo READ Scale WRITE setScale)
private:
	//! Целевая функция.
	const funkcio * F;
	//! Сцена
	ScenoPorMapo *s;
	//! "След"
	spuro * Spuro;
public:
	MapoPorFunkcioImpl( const funkcio * Funkcio, //!< Указатель на целевую функцию. ScenoPorMapo не заботится о назначении Funkcio родителя.
	                    QWidget * parent = 0, //!< Родитель.
	                    Qt::WFlags f = 0 //!< Флаги параметров окна.
	                  );
	MapoPorFunkcioImpl( QWidget * parent = 0, //!< Родитель.
	                    Qt::WFlags f = 0 //!< Флаги параметров окна.
	                  );
	/*! Возвращает указатель на "след" прохождения алгоритма.
	 * 
	 * "Следы" разных алгоритмов имеют разные слоты.
	 * @see spuro, spuroSinkoLauxKoordinatoj.
	 */
	const spuro * proviziSpuro() const;
	//! Возвращает множитель масштабирования.
	qreal Scale() const;
public slots:
	/*! Устанавливает масштаб.
	 * 
	 * @param factor Множитель масштабирования. factor = 1 - масштаб 1:1.
	 */
	void setScale(qreal factor);
	//! Устанавливает целевую функцию.
	void difiniFunkcio(funkcio * f);
	//! Создает на сцене "след" алгоритма.
	void kreiSpuro(
	               int IdAlgoritmo, //!< Порядковый номер алгоритма(см. A).
	               QColor bazaKoloro //!< Основной цвет "следа".
	              );
private slots:
	//! Увеличить масштаб.
	void on_PligrandigiBtn_clicked();
	//! Уменьшить масштаб.
	void on_MalpliigiBtn_clicked();
};
#endif


/*! @class MapoPorFunkcioImpl
 * Карта высот отображается на фоне сцены. Поверх её рисуется "след" оставляемый алгоритмом. Каждый алгоритм имеет свой "след". Базовым для всех "следов" является класс spuro.
 * Для создания "следа" используется метод void kreiSpuro( int IdAlgoritmo, QColor bazaKoloro) в который передаётся порядковый номер алгоритма(см. A) и основной цвет. На сцене может быть создан только один "след".
 * Руководство по работе со следами конкретного алгоритма см. в описании соответствующего класса.
 * 
 * spuroSinkoLauxKoordinatoj - "след" по координатного спуска с фиксированным шагом.
 *  - "след"
 *  - "след"
 *  - "след"
 *  - "след"
 * 
 * Метод const spuro * proviziSpuro() возвращает указатель на существующий "след" прохождения алгоритма.
 * 
 * @author Василий Почкаенко.
 */
