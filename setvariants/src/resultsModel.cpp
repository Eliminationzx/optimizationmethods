#include "resultsModel.h"

resultsModel::resultsModel(QObject *parent) :
  QAbstractTableModel(parent),
  m_data(QList<QList<QString> >())
{
	{
		QList<QString> stud;
		stud.append(trUtf8("БИ71"));
		stud.append(trUtf8("Иванов Иван Иванович"));
		stud.append(trUtf8("3"));
		stud.append(trUtf8("8"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("5"));
		stud.append(trUtf8("2"));
		stud.append(trUtf8("7"));
		stud.append(trUtf8("2"));
		m_data.append(stud);
	}
	{
		QList<QString> stud;
		stud.append(trUtf8("БИ71"));
		stud.append(trUtf8("Петров Пётр Петрович"));
		stud.append(trUtf8("9"));
		stud.append(trUtf8("7"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("5"));
		stud.append(trUtf8("2"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("1"));
		stud.append(trUtf8("4"));
		m_data.append(stud);
	}
	{
		QList<QString> stud;
		stud.append(trUtf8("БИ71"));
		stud.append(trUtf8("Сидоров Сидор Сидорович"));
		stud.append(trUtf8("1"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("5"));
		stud.append(trUtf8("3"));
		stud.append(trUtf8("8"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("4"));
		m_data.append(stud);
	}
	{
		QList<QString> stud;
		stud.append(trUtf8("БИ71"));
		stud.append(trUtf8("Никитин Никита Никитович"));
		stud.append(trUtf8("5"));
		stud.append(trUtf8("7"));
		stud.append(trUtf8("2"));
		stud.append(trUtf8("6"));
		stud.append(trUtf8("7"));
		stud.append(trUtf8("2"));
		stud.append(trUtf8("3"));
		stud.append(trUtf8("2"));
		m_data.append(stud);
	}
	{
		QList<QString> stud;
		stud.append(trUtf8("БИ72"));
		stud.append(trUtf8("Кириллов Кирилл Кириллович"));
		stud.append(trUtf8("3"));
		stud.append(trUtf8("2"));
		stud.append(trUtf8("5"));
		stud.append(trUtf8("3"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("5"));
		stud.append(trUtf8("3"));
		stud.append(trUtf8("7"));
		m_data.append(stud);
	}
	{
		QList<QString> stud;
		stud.append(trUtf8("БИ72"));
		stud.append(trUtf8("Семенов Семен Семенович"));
		stud.append(trUtf8("0"));
		stud.append(trUtf8("3"));
		stud.append(trUtf8("8"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("2"));
		stud.append(trUtf8("1"));
		stud.append(trUtf8("7"));
		stud.append(trUtf8("5"));
		m_data.append(stud);
	}
	{
		QList<QString> stud;
		stud.append(trUtf8("БИ72"));
		stud.append(trUtf8("Андреев Андрей Андреевич"));
		stud.append(trUtf8("7"));
		stud.append(trUtf8("3"));
		stud.append(trUtf8("1"));
		stud.append(trUtf8("2"));
		stud.append(trUtf8("5"));
		stud.append(trUtf8("7"));
		stud.append(trUtf8("4"));
		stud.append(trUtf8("1"));
		m_data.append(stud);
	}
	{
		QList<QString> stud;
		stud.append(trUtf8("БИ72"));
		stud.append(trUtf8("Александрова Александра Александровна"));
		stud.append(trUtf8("3"));
		stud.append(trUtf8("8"));
		stud.append(trUtf8("5"));
		stud.append(trUtf8("2"));
		stud.append(trUtf8("9"));
		stud.append(trUtf8("2"));
		stud.append(trUtf8("9"));
		stud.append(trUtf8("1"));
		m_data.append(stud);
	}
}

/** Используется другими компонентами для получения информации о каждом элементе, предоставляемом моделью.*/
Qt::ItemFlags resultsModel::flags( const QModelIndex & index ) const{
	return flags(index);
}

/** Снабжает представления и делегаты данными элементов.*/
QVariant resultsModel::data( const QModelIndex & index, int role) const{
	if(index.parent() == QModelIndex())
		return QVariant();
	
	if(index.row() >= m_data.count() || index.column() >= m_data.at(0).count())
		return QVariant();
	
	return m_data.at(index.row()).at(index.column());
}

/** Предоставляется представлениям с информацией для показа в их заголовках..*/
QVariant resultsModel::headerData( int section, Qt::Orientation orientation, int role) const{
	if(orientation == Qt::Horizontal)
	{
		switch (section)
		{
			case 0:
				return trUtf8("Квадратичная");
			case 1:
				return trUtf8("Квадратичная");
			case 2:
				return trUtf8("Квадратичная");
			case 3:
				return trUtf8("Квадратичная");
			case 4:
				return trUtf8("Овражная");
			case 5:
				return trUtf8("Квадратичная");
			case 6:
				return trUtf8("Квадратичная");
			case 7:
				return trUtf8("Овражная");
			default:
				return QVariant();
		}
	}
	else
		return section + 1;
	
}

/** Количество строк данных, доступных в модели.*/
int resultsModel::rowCount( const QModelIndex & parent) const{
	return m_data.count();
}

/** Количество столбцов данных, доступных в модели.*/
int resultsModel::columnCount( const QModelIndex & parent) const{
	return m_data.at(0).count();
}

/** Получая модельный индекс родительского элемента, эта функция позволяет представлениям и делегатам обращаться к дочерним элементам этого элемента.*/
QModelIndex resultsModel::index( int row, int column, const QModelIndex & parent) const{
	if(parent != QModelIndex())
		return QModelIndex();
	
//	return index(row, column, parent);
//	QModelIndex(row, column, &(m_data[row][column]), this);
	createIndex(row, column, row*column);
}

/** Возвращает модельный индекс, соответствующий родителю какого-либо дочернего элемента..*/
QModelIndex resultsModel::parent( const QModelIndex & index ) const{
	return QModelIndex();
}

