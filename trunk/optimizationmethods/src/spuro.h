#ifndef SPURO_H
#define SPURO_H
//
#include <QGraphicsItem>
#include <QObject>
#include "Konstantoj.h"
//
//! Базовый класс для отображения "следа" алгоритма.
/*! Этот класс не проверяет логику прохождения алгоритма. Он лишь позволяет нарисовать "след" на сцене.
 * 
 * @author Василий Почкаенко.
 * @file spuro.h
 */
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
  void setScale(qreal factor);
  //! Возвращает порядковый номер алгоритма.
  inline int proviziIdAlgoritmo(){ return IDAlgoritmo; };
  //! Возвращает значение основного цвета.
  /*! @see A.
   * 
   */
  inline QColor proviziBazaKoloro(){ return BazaKoloro; };
  
  spuro(int IdAlgoritmo, //!< Порядковый номер алгоритма(@see A).
        QColor bazaKoloro, //!< Основной цвет "следа".
        QGraphicsItem * parent = 0 //!< Элемент родитель.
       );
};
#endif
