#ifndef SCENOPORMAPO_H
#define SCENOPORMAPO_H
//
#include <QGraphicsScene>
//
class funkcio;
//! Сцена для карты высот целевой функции.
/*! Отличается от стандартной QGraphicsScene тем, что рисует на фоне карту высот.
 * В классе собственая реализация масштабирования. Работа с масштабом подобна работе в QPainter. @see scale();
 * @author Василий Почкаенко.
 * @file scenopormapo.h
 */
class ScenoPorMapo : public QGraphicsScene
{
Q_OBJECT
private:
  //! Целевая функция.
  funkcio *F;
  //! Коэффициент масштаба.
  qreal skalo;
public:
  //! Возвращает масштаб.
  qreal scale() const;
  //! Устанавливает масштаб.
  void setScale(qreal factor);
  
  ScenoPorMapo( funkcio * Funkcio, QObject * parent = 0);
  ScenoPorMapo( funkcio * Funkcio, const QRectF & sceneRect, QObject * parent = 0);
  ScenoPorMapo( funkcio * Funkcio, qreal x, qreal y, qreal width, qreal height, QObject * parent = 0);
public slots:
  //! Создает на сцене "след" алгоритма.
  void kreiSpuro(
                 int IdAlgoritmo, //!< Порядковый номер алгоритма.
                 QColor bazaKoloro //!< Основной цвет "следа".
                );
protected:
  //! Отрисовывает фон сцены с использованием painter перед отрисовкой любого элемента или переднего плана.
  void drawBackground(QPainter * painter, const QRectF & rect);
};
#endif
