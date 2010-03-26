#ifndef BAZOMAPO_H
#define BAZOMAPO_H
//
#include <QGraphicsItem>
//
class funkcio;
//! Основа карты.
/*! Класс реализует элемент QGraphicsScene. Рисует прямоугольник с картой высот функции. Является фоном всей сцены.
 * @author Василий Почкаенко.
 * @file bazomapo.h
 */
class BazoMapo : public QGraphicsItem{
//Q_OBJECT
private:
  //! Целевая функция.
  funkcio *F;
public:
  // Возвращает размер области в которую заключена фигура.
  QRectF boundingRect() const;
  BazoMapo(QGraphicsItem * parent = 0);
  
};
#endif
