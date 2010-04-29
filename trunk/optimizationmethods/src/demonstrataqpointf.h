#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include <QObject>
//
//! Обёртка QPointF, дла автоматического отображения его значений в окне.
class DemonstrataQPointF : public QObject{
Q_OBJECT
Q_PROPERTY(qreal x READ x WRITE setX)
Q_PROPERTY(qreal y READ y WRITE setY)
private:
	QPointF p;
public: 
  /* @return истина если обе координаты, х и у, равны 0.0, в противном случае ложь.
  */
	bool isNull() const;
  /*! @return сумма абсолютных величин x() и y(),
  */ 
	qreal manhattanLength() const;
  //! Возвращает значение X по ссылке.
  qreal & rx();
  //! Возвращает значение Y по ссылке.
  qreal & ry();
  //! Возвращает копию самой точки, округленой до целых.
	QPoint toPoint () const;
  //! Возвращает копию самой точки.
	QPointF toPointF () const;
  //! Устанавливает новое значение X.
  void setX(qreal x);
  //! Устанавливает новое значение Y.
  void setY(qreal y);
  QPointF & operator*=(qreal factor);
  QPointF & operator+=(const DemonstrataQPointF & point);
  QPointF & operator-=(const DemonstrataQPointF & point);
  QPointF & operator/=(qreal divisor);
  //! Возвращает значение X.
  qreal x();
  //! Возвращает значение Y.
  qreal y();
  DemonstrataQPointF( QObject * parent = 0);
  DemonstrataQPointF( const QPoint & point, QObject * parent = 0);
  DemonstrataQPointF( qreal x, qreal y, QObject * parent = 0);
  /*! Конструктор копирования.
   * Копирует только точку. Поля унаследованные от QObject оставляет по умолчанию.
	 */
  DemonstrataQPointF( DemonstrataQPointF & DP);
signals:
  //! Предоставляет значение в виде точки.
  void proviziValoro(QPointF);
  //! Предоставляет значение в виде целого числа.
  void proviziXValoro(int);
  //! Предоставляет значение в виде десятичной дроби.
  void proviziXValoro(double valoro);
  //! Предоставляет значение в виде строки.
  void proviziXValoro(const QString &);
  //! Предоставляет значение в виде целого числа.
  void proviziYValoro(int);
  //! Предоставляет значение в виде десятичной дроби.
  void proviziYValoro(double valoro);
  //! Предоставляет значение в виде виде строки.
  void proviziYValoro(const QString &);  
};

  //! Возвращает истину если p1 не равно p2; в противном случае возвращает ложь.
	bool operator!= ( const DemonstrataQPointF & p1, const QPointF & p2 );
  /*! Это перегруженная функция.
	 * Возвращает истину если p1 не равно p2; в противном случае возвращает ложь.
	 */
	bool operator!= ( const QPointF & p1, const DemonstrataQPointF & p2 );
  /*! Это перегруженная функция.
	 *  Возвращает истину если p1 не равно p2; в противном случае возвращает ложь.
	 */
	bool operator!= ( const DemonstrataQPointF & p1, const DemonstrataQPointF & p2 );


  //! Возвращает копию точки point, умноженной на factor.
  const QPointF operator* ( const DemonstrataQPointF & point, qreal factor );
  /*! Это перегруженная функция.
	 * Возвращает копию точки point, умноженной на factor.
	 */
  const QPointF operator* ( qreal factor, const DemonstrataQPointF & point );


  /*! Возвращает объект QPointF, который является суммой точек, p1 и p2; каждый
   * компонент добавляется отдельно.
	 */
  const QPointF operator+( const DemonstrataQPointF & p1, const QPointF & p2 );
  /*! Это перегруженная функция.
	 * Возвращает объект QPointF, который является суммой точек, p1 и p2; каждый
   * компонент добавляется отдельно.
	 */
  const QPointF operator+( const QPointF & p1, const DemonstrataQPointF & p2 );
  /*! Это перегруженная функция.
	 * Возвращает объект QPointF, который является суммой точек, p1 и p2; каждый
   * компонент добавляется отдельно.
	 */
  const QPointF operator+ ( const DemonstrataQPointF & p1, const DemonstrataQPointF & p2 );


  /*! Возвращает объект QPointF, который получается вычитанием p1 из p2; каждый
   * компонент вычитается отдельно.
	 */
  const QPointF operator- ( const DemonstrataQPointF & p1, const QPointF & p2 );
  /*! Это перегруженная функция.
	 * Возвращает объект QPointF, который получается вычитанием p1 из p2; каждый
   * компонент вычитается отдельно.
	 */
  const QPointF operator- ( const QPointF & p1, const DemonstrataQPointF & p2 );
  /*! Это перегруженная функция.
	 * Возвращает объект QPointF, который получается вычитанием p1 из p2; каждый
   * компонент вычитается отдельно.
	 */
  const QPointF operator- ( const DemonstrataQPointF & p1, const DemonstrataQPointF & p2 );


  /*! Это перегруженная функция.
	 * Возвращает объект QPointF, который получается изменением знака обоих
	 * компонентов точки point.
	 */
  const QPointF operator- ( const DemonstrataQPointF & point );


  /*! Возвращает QPointF получаемый делением обоих компонентов точки point на
   * заданный делитель divisor.
   */
  const QPointF operator/ ( const DemonstrataQPointF & point, qreal divisor );


  //! Записывает точку point в заданный поток stream и возвращает ссылку на поток.
  QDataStream & operator<< ( QDataStream & stream, const DemonstrataQPointF & point );
 
 
  //! Возвращает истину если p1 равно p2 ; в противном случае возвращает ложь.
  bool operator== ( const DemonstrataQPointF & p1, const QPointF & p2 );
  /*! Это перегруженная функция.
	 * Возвращает истину если p1 равно p2 ; в противном случае возвращает ложь.
	 */
  bool operator== ( const QPointF & p1, const DemonstrataQPointF & p2 );
  /*! Это перегруженная функция.
	 * Возвращает истину если p1 равно p2 ; в противном случае возвращает ложь.
	 */
  bool operator== ( const DemonstrataQPointF & p1, const DemonstrataQPointF & p2 );


  /*! Читает точку из потока stream в заданную точку point и возвращает ссылку
   * на поток.
   */
  QDataStream & operator>> ( QDataStream & stream, DemonstrataQPointF & point );

#endif

/*! @class DemonstrataQPointF
 * К QPointF добавлены сигалы передающие его значение. Эти сигналы вызываются во всех методах изменяющих значение точки.
 * 
 * @author Василий Почкаенко.
 */
