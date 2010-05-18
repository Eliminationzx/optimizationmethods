#ifndef SPUROSINKOLAUXKOORDINATOJ_H
#define SPUROSINKOLAUXKOORDINATOJ_H
//
#include "spuro.h"
//
//! Отображает "след" по координатного спуска с дискретным шагом.
class spuroSinkoLauxKoordinatoj : public spuro
{
Q_OBJECT
private:
	//! Цвет текущей итерации.
	QColor MomentaKoloro;
	//! Точки прошедших итераций.
	QPolygonF Vosto;
	//! Точки текущей итерации.
	QPolygonF MomentaPointoj;
	//! Текущая точка.
	QPointF MomentaPointo;
protected:
	//! Применяет масштаб к полигонам.
	virtual QPolygonF aplikiScalo(QPolygonF p);
public:
	//! Реализует отрисовку элемента.
	void paint(QPainter *painter, //!< Контекст рисования элемента.
	           const QStyleOptionGraphicsItem *option, //!< Опции стилей для элементов, такие как его состояние, область отображения и подсказки степени его детализации.
	           QWidget *widget = 0 //!< Указывает на виджет, который отрисовывается; в противном случае он равен 0. Для кэшированного рисования widget всегда равен 0.
	          );
	//! Возвращает приблизительную площадь отрисовываемую элементом.
	QRectF boundingRect() const;
	
	spuroSinkoLauxKoordinatoj(QColor momentaKoloro, //!< Цвет текущей итерации.
	                          QColor bazaKoloro, //!< Основной цвет "следа".
	                          qreal Skalo = 1, //!< Коэффициент масштаба.
	                          QGraphicsItem * parent = 0 //!< Элемент родитель.
	                         );
public slots:
	/*! Установить первую точку.
	 * 
	 * Устанавливает точку с которой начинается поиск.
	 */
	void difiniUnuaPointo( QPointF p );
	//! Перегружает difiniUnuaPointo(QPointF &p).
	void difiniUnuaPointo( qreal x, qreal y );
	/*! Завершить итерацию.
	 * 
	 * Делает последнюю точку из MomentaPointoj основной точкой текущей итерации.
	 * Переносит точки завершаемой итерации в "хвост".
	 * Заменяет список точек текущей итерации на вновь полученную основную точку текущей итерации.
	 */
	void finisxiIteracio();
	//! Вернуться к текущей точке.
	void reveniAlMomentoPointo();
	//! Добавить точку поиска.
	void aldoniSercxantaPointo(QPointF);
	//! Установить текущую точку.
	void difiniMomentaPointo(QPointF);
	//! Установить базовый цвет.
	void difiniBazaKoloro(QColor bazaKoloro);
	//! Установить текущий цвет.
	void difiniMomentaKoloro(QColor momentaKoloro);
	//! Очищает "хвост".
	void senspurigi();
};
#endif

/*! @class spuroSinkoLauxKoordinatoj
 * Этот "след" представляет собой ломаную линию, соединяющую установленные для него точки.
 * Рисует прошедшие итерации основным цветом - BazaKoloro, а текущую MomentaKoloro.
 *
 * Этот класс не проверяет логику прохождения алгоритма. Он лишь позволяет нарисовать "след" на сцене.
 *
 * Сразу же после создания "следа" необходимо задать начальную точку. Для этого используется слот void difiniUnuaPointo( QPointF p ).
 *
 * В классе создана основная точка итерации - MomentaPointo. Это точка вокруг которой ведётся поиск. Для каждой итерации эта точка должна быть обновлена.
 *
 * Чтобы добавить точку поиска воспользуйтесь слотом void aldoniSercxantaPointo(QPointF). Если точка поиска не оказалась меньше основной точки итерации, то вызовите слот void reveniAlMomentoPointo(). Не забывайте возвращаться назад.
 *
 * Если итерация закончена вызовите слот void finisxiIteracio(). Обратите внимание, что finisxiIteracio задаёт в качестве основной точки новой итерации последнюю точку из списка завершённой итерации. Не забывайте возвращаться назад с помощью reveniAlMomentoPointo().
 *
 * @code
//=========Пример==============================================================
  MapoWdg->kreiSpuro(A::CWdescent_fix, Qt::blue);
  spuroSinkoLauxKoordinatoj Sp = MapoWdg->proviziSpuro();

  //------Итерация 1-----------------------------------------------------------
  Sp->difiniUnuaPointo(QPoint(0, 0));
  Sp->aldoniSercxantaPointo(QPoint(10, 0));
  //spuroSinkoLauxKoordinatoj не проверяет логику.
  //Он соединяет подрят все переданные ему точки.
  //В следующей строке совершена ошибка с точки зрения алгоритма.
  Sp->aldoniSercxantaPointo(QPoint(20, 10));
  //! Завершаю итерацию.
  Sp->finisxiIteracio();

  //------Итерация 2-----------------------------------------------------------
  //! Далее буду следовать алгоритму Покоординатного спуска.
  Sp->aldoniSercxantaPointo(QPoint(20+10, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  //Вернусь назад.
  Sp->reveniAlMomentoPointo();
  Sp->aldoniSercxantaPointo(QPoint(20-10, 10));
  //Пусть значение в новой точке меньше чем в базовой.
  //Ура, завершаю итерацию.
  Sp->finisxiIteracio();
  //------Итерация 3-----------------------------------------------------------
  Sp->aldoniSercxantaPointo(QPoint(10+5, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  Sp->aldoniSercxantaPointo(QPoint(10-5, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  Sp->aldoniSercxantaPointo(QPoint(10, 10+5));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  Sp->aldoniSercxantaPointo(QPoint(10, 10-5));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  //Надо уменьшить шаг и прейти к следующей итерации.
  Sp->finisxiIteracio();
  //------Итерация 4-----------------------------------------------------------
  Sp->aldoniSercxantaPointo(QPoint(10+2.5, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  Sp->aldoniSercxantaPointo(QPoint(10-2.5, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  Sp->aldoniSercxantaPointo(QPoint(10, 10+2.5));
  //Пусть значение в новой точке меньше чем в базовой.
  Sp->finisxiIteracio();
  //------Итерация 5-----------------------------------------------------------
  Sp->aldoniSercxantaPointo(QPoint(10+1.25, 12.5));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  Sp->aldoniSercxantaPointo(QPoint(10-1.25, 12.5));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  Sp->aldoniSercxantaPointo(QPoint(10, 12.5+1.25));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  Sp->aldoniSercxantaPointo(QPoint(10, 12.5-1.25));
  //Пусть значение в новой точке неменьше чем в базовой.
  Sp->reveniAlMomentoPointo();
  //Надо уменьшить шаг.
  //Пусть новый шаг меньше заданной тосности.
  //!!!!!!Ура, нашли минимум!!!!!!!!!!!!!!!!
//=============================================================================
 * @endcode
 * В примере aldoniSercxantaPointo, reveniAlMomentoPointo, finisxiIteracio вызываются на прямую. Но все они являются слотами и могут быть соединены с сигналами.
 * @author Василий Почкаенко.
 */