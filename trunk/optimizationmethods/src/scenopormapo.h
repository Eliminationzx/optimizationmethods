#ifndef SCENOPORMAPO_H
#define SCENOPORMAPO_H
//
#include <QGraphicsScene>
//
class funkcio;
class spuro;
//! Сцена для карты высот целевой функции.
class ScenoPorMapo : public QGraphicsScene
{
Q_OBJECT
private:
  //! Целевая функция.
  funkcio *F;
  //! Коэффициент масштаба.
  qreal skalo;
  //! Указатель на след.
  spuro * Sp;
public:
  //! Возвращает масштаб.
  qreal scale() const;

  ScenoPorMapo( funkcio * Funkcio, QObject * parent = 0);
  ScenoPorMapo( funkcio * Funkcio, const QRectF & sceneRect, QObject * parent = 0);
  ScenoPorMapo( funkcio * Funkcio, qreal x, qreal y, qreal width, qreal height, QObject * parent = 0);
public slots:
  //! Устанавливает масштаб.
  void setScale(qreal factor);
protected:
  //! Отрисовывает фон сцены с использованием painter перед отрисовкой любого элемента или переднего плана.
  void drawBackground(QPainter * painter, const QRectF & rect);
};
#endif

/*! @class ScenoPorMapo
 * Отличается от стандартной QGraphicsScene тем, что рисует на фоне карту высот.
 * В классе собственная реализация масштабирования.
 * 
 * @author Василий Почкаенко.
 * @file scenopormapo.h
 */