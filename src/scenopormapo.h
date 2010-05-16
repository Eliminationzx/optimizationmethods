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
public:
  //! Возвращает масштаб.
  qreal scale() const;

  ScenoPorMapo( funkcio * Funkcio, //!< Указатель на целевую функцию. ScenoPorMapo не заботится о назначении Funkcio родителя.
                QObject * parent = 0 //!< Родитель.
              );
  ScenoPorMapo( funkcio * Funkcio, //!< Указатель на целевую функцию. ScenoPorMapo не заботится о назначении Funkcio родителя.
                const QRectF & sceneRect, //!< Область сцены.
                QObject * parent = 0 //!< Родитель.
              );
  ScenoPorMapo( funkcio * Funkcio, //!< Указатель на целевую функцию. ScenoPorMapo не заботится о назначении Funkcio родителя.
                qreal x, //!< Горизонтальная координата левого верхнего угла сцены.
                qreal y, //!< Вертиктальная координата левого верхнего угла сцены.
                qreal width, //!< Ширина сцены.
                qreal height, //!< Высота сцены.
                QObject * parent = 0 //!< Родитель.
              );
public slots:
  //! Устанавливает масштаб.
  /*! @param factor Множитель масштабирования. factor = 1 - масштаб 1:1.
   */
  void setScale(qreal factor);
protected:
  //! Обработчик перемещения мыши.
  /*! Высылаются сигналы о положении мыши. Затем вызывается реализация поумолчанию.
   */
  void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
  //! Отрисовывает фон сцены с использованием painter перед отрисовкой любого элемента или переднего плана.
  void drawBackground(QPainter * painter, //!< Контекст рисования фона сцены.
                      const QRectF & rect //!< Область сцены.
                     );
signals:
  void MusaPosX(const qreal);
  void MusaPosY(const qreal);
  void MusaPos(const QString );
};

#endif

/*! @class ScenoPorMapo
 * Отличается от стандартной QGraphicsScene тем, что рисует на фоне карту высот.
 * В классе собственная реализация масштабирования.
 * 
 * @author Василий Почкаенко.
 */