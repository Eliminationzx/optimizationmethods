#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QAbstractTableModel>
/**
 *
 * @author Василий Почкаенко
 */
class resultsModel : public QAbstractTableModel{
Q_OBJECT
private:
	QList<QList<QString> > m_data;
public:
	explicit resultsModel(QObject *parent = 0);

	/** Используется другими компонентами для получения информации о каждом элементе, предоставляемом моделью.*/
	virtual Qt::ItemFlags flags( const QModelIndex & index ) const;

	/** Снабжает представления и делегаты данными элементов.*/
	virtual QVariant data( const QModelIndex & index, int role = Qt::DisplayRole ) const;

	/** Предоставляется представлениям с информацией для показа в их заголовках..*/
	virtual QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

	/** Количество строк данных, доступных в модели.*/
	virtual int rowCount( const QModelIndex & parent = QModelIndex() ) const;

	/** Количество столбцов данных, доступных в модели.*/
	virtual int columnCount( const QModelIndex & parent = QModelIndex() ) const;

	/** Получая модельный индекс родительского элемента, эта функция позволяет представлениям и делегатам обращаться к дочерним элементам этого элемента.*/
	virtual QModelIndex index( int row, int column, const QModelIndex & parent = QModelIndex() ) const;

	/** Возвращает модельный индекс, соответствующий родителю какого-либо дочернего элемента..*/
	QModelIndex parent( const QModelIndex & index ) const;
signals:

public slots:

};

#endif // IMAGEMODEL_H
