#ifndef SPURO_H
#define SPURO_H
//
#include <QGraphicsItem>
#include <QObject>
#include "Konstantoj.h"
//
//! Базовый класс для отображения "следа" алгоритма.
class spuro : public QObject , public QGraphicsItem
{
Q_OBJECT
protected:
  //! Коэффициент масштаба.
  qreal skalo;
  //! Основной цвет "следа".
  QColor BazaKoloro;
  //! Порядковый номер алгоритма.
  /*! @see A.
   * 
   */
  int IDAlgoritmo;
public:
  //! Возвращает масштаб.
  qreal scale() const;
  //! Устанавливает масштаб.
  /*! @param factor Множитель масштабирования. factor = 1 - масштаб 1:1.
   */
  void setScale(qreal factor);
  //! Возвращает порядковый номер алгоритма.
  inline int proviziIdAlgoritmo() const { return IDAlgoritmo; };
  /*! Возвращает значение основного цвета.
   * 
   * @see A.
   */
  inline QColor proviziBazaKoloro() const { return BazaKoloro; };
  
  spuro(int IdAlgoritmo, //!< Порядковый номер алгоритма(см. A).
        QColor bazaKoloro, //!< Основной цвет "следа".
        QGraphicsItem * parent = 0 //!< Элемент родитель.
       );
};
#endif

/*! @class spuro
 * Этот класс не проверяет логику прохождения алгоритма. Он лишь позволяет нарисовать "след" на сцене.
 * 
 * @author Василий Почкаенко.
 */
