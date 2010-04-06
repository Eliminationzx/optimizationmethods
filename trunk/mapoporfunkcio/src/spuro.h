#ifndef SPURO_H
#define SPURO_H
//
#include <QGraphicsItem>
//
//! Базовый класс для отображения "следа" алгоритма.
/*! 
 * 
 * @author Василий Почкаенко.
 * @file spuro.h
 */
class spuro : public QGraphicsItem
{
private:
  //! Основной цвет "следа".
  QColor BazaKoloro;
  //! Название алгоритма.
  QString Nomo;
public:
  //! Возвращает название алгоритма.
  inline QString proviziNomo(){ return Nomo; };
  //! Возвращает значение основного цвета.
  inline QColor proviziBazaKoloro(){ return BazaKoloro; };
  
  spuro(QString nomo, //!< Название алгоритма.
        QColor bazaKoloro, //!< Основной цвет "следа".
        QGraphicsItem * parent = 0 //!< Элемент родитель.
       );
};
#endif
