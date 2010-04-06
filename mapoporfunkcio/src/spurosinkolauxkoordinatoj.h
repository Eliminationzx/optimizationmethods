#ifndef SPUROSINKOLAUXKOORDINATOJ_H
#define SPUROSINKOLAUXKOORDINATOJ_H
//
#include "spuro.h"
//
//! Отображет "след" покоординатного спуска с дискретным шагом.
/*! Рисует прошедьшие итерации осчновныи цветом - BazaKoloro, а текущую MomentaKoloro.
 * 
 * @author Василий Почкаенко.
 * @file spurosinkolauxkoordinatoj.h
 */
class spuroSinkoLauxKoordinatoj : public spuro
{
private:
  //! Коэффициент масштаба.
  qreal skalo;
  //! Цвет текущей итерации.
  QColor MomentaKoloro;
  //! Точки прошедьших итераций.
  QPolygon Vosto;
  //! Точки текущей итерации.
  QPolygon MomentaPointioj;
  //! Текущая точка.
  /*! Вокруг неё ведётся поиск.
  */
  QPointF MomentaPointio;
public:
  //! Возвращает масштаб.
  qreal scale() const;
  //! Устанавливает масштаб.
  void setScale(qreal factor);
  //! Реализует отрисовку элемента.
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widge);
  //! Возвращает приблизительную площадь отрисовываемую элементом.
  QRectF boundingRect() const;
  
	spuroSinkoLauxKoordinatoj(QColor momentaKoloro, //!< Цвет текущей итерации.
                            QColor bazaKoloro, //!< Основной цвет "следа".
                            QGraphicsItem * parent = 0 //!< Элемент родитель.
                           );
public slots:
  //! Завершить итерацию.
  /*! Делает последнюю используованную в итерации точку текущей. 
   * Переносит точки завершаемой итерации в "хвост".
   * Заменяет список точек текущей итерации на вновь полученную текущую точку.
   */
  void finisxiIteracio();
  //! Вернуться к текущей точке.
  void reveniAlMomentoPointo();
  //! Добавить точку поиска.
  void aldoniSercxantaPointo(QPointF);
};
#endif
