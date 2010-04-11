#ifndef SPUROSINKOLAUXKOORDINATOJ_H
#define SPUROSINKOLAUXKOORDINATOJ_H
//
#include "spuro.h"
//
//! Отображает "след" по координатного спуска с дискретным шагом.
/*! Рисует прошедшие итерации основным цветом - BazaKoloro, а текущую MomentaKoloro.
 * Этот класс не проверяет логику прохождения алгоритма. Он лишь позволяет нарисовать "след" на сцене.
 * Сразу же после создания "следа" необходимо задать начальную точку. Для этого используется слот void difiniUnuaPointo( QPointF p ).
 * В классе создана основная точка итерации - MomentaPointio. Это точка вокруг которой ведётся поиск. Для каждой итерации эта точка должна быть обновлена.
 * Чтобы добавить точку поиска воспользуйтесь слотом void aldoniSercxantaPointo(QPointF). Если точка поиска не оказалась меньше основной точки итерации, то вызовите слот void reveniAlMomentoPointo(). Не забывайте возвращаться назад.
 * Если итерация закончена вызовите слот void finisxiIteracio(). Обратите внимание, что finisxiIteracio задаёт в качестве основной точки новой итерации последнюю точку из списка завершённой итерации. Не забывайте возвращаться назад с помощью reveniAlMomentoPointo.
 *
 * @author Василий Почкаенко.
 * @file spurosinkolauxkoordinatoj.h
 */
class spuroSinkoLauxKoordinatoj : public spuro
{
private:
  //! Цвет текущей итерации.
  QColor MomentaKoloro;
  //! Точки прошедших итераций.
  QPolygonF Vosto;
  //! Точки текущей итерации.
  QPolygonF MomentaPointioj;
  //! Базовая точка текущей итерации.
  /*! Вокруг неё ведётся поиск.
  */
  QPointF MomentaPointio;
protected:
  //! Применяет масштаб к полигонам.
  virtual QPolygonF aplikiScalo(QPolygonF p);
public:
  //! Реализует отрисовку элемента.
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widge);
  //! Возвращает приблизительную площадь отрисовываемую элементом.
  QRectF boundingRect() const;

	spuroSinkoLauxKoordinatoj(QColor momentaKoloro, //!< Цвет текущей итерации.
                            QColor bazaKoloro, //!< Основной цвет "следа".
                            QGraphicsItem * parent = 0 //!< Элемент родитель.
                           );
public slots:
  //! Установить первую точку.
  /*! Устанавливает точку с которой начинается поиск.
   */
  void difiniUnuaPointo( QPointF p );
  //! Перегружает difiniUnuaPointo(QPointF &p).
  void difiniUnuaPointo( qreal x, qreal y );
  //! Завершить итерацию.
  /*! Делает последнюю точку из MomentaPointioj основной точкой текущей итерации.
   * Переносит точки завершаемой итерации в "хвост".
   * Заменяет список точек текущей итерации на вновь полученную основную точку текущей итерации.
   */
  void finisxiIteracio();
  //! Вернуться к текущей точке.
  void reveniAlMomentoPointo();
  //! Добавить точку поиска.
  void aldoniSercxantaPointo(QPointF);
};
#endif
