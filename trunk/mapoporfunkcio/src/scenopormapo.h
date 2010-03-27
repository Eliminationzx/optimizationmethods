#ifndef SCENOPORMAPO_H
#define SCENOPORMAPO_H
//
#include <QGraphicsScene>
//
class funkcio;
//! Сцена для карты высот целевой функции.
/*! Отличается от стандартной QGraphicsScene тем, что рисует на фоне карту высот.
 * @author Василий Почкаенко.
 * @file scenopormapo.h
 */
class ScenoPorMapo : public QGraphicsScene
{
Q_OBJECT
private:
  //! Целевая функция.
  funkcio *F;
public slots:
  //! Планирует перерисовку области сцены rect.
  void update(const QRectF & rect = QRectF());
public:
  ScenoPorMapo( funkcio * Funkcio, QObject * parent = 0);
  ScenoPorMapo( funkcio * Funkcio, const QRectF & sceneRect, QObject * parent = 0);
  ScenoPorMapo( funkcio * Funkcio, qreal x, qreal y, qreal width, qreal height, QObject * parent = 0);
  
};
#endif
