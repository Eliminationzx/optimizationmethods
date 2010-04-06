#ifndef SPURO_H
#define SPURO_H
//
#include <QGraphicsItem>
#include <QObject>
//
//! Базовый класс для отображения "следа" алгоритма.
/*! 
 * 
 * @author Василий Почкаенко.
 * @file spuro.h
 */
class spuro : public QObject , public QGraphicsItem
{
Q_OBJECT
private:
  //! Основной цвет "следа".
  QColor BazaKoloro;
  //! Порядковый номер алгоритма.
  /*! 0) метод покоординатного спуска с дискретным шагом
   * 1) метод покоординатного спуска с минимизацией по направлению
   * 2) метод наискорейшего спуска
   * 3) метод Хука-Дживса
   * 4) метод Нелдера-Мида
   * 5) метод Ньютона
   */
  int IDAlgoritmo;
public:
  //! Возвращает название алгоритма.
  inline int proviziIdAlgoritmo(){ return IDAlgoritmo; };
  //! Возвращает значение основного цвета.
  inline QColor proviziBazaKoloro(){ return BazaKoloro; };
  
  spuro(int IdAlgoritmo, //!< Порядковый номер алгоритма.
        QColor bazaKoloro, //!< Основной цвет "следа".
        QGraphicsItem * parent = 0 //!< Элемент родитель.
       );
};
#endif
