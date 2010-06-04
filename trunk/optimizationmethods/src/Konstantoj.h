#ifndef __KONSTANTOJ_H__
#define __KONSTANTOJ_H__

//! Константы обозначающие алгоритм.
namespace A{
  //! Покоординатный спуск с фиксированным шагом.
  const int CWdescent_fix = 0;
  //! Покоординатный спуск с минимизацией по направлению.
  const int CWdescent_md = 1;
  //! Наискорейший спуск.
  const int FasterDescent = 2;
  //! Метод Хука-Дживса.
  const int HuGi = 3;
  //! Метод Нелдера-Мида.
  const int NeMi = 4;
  //! Метод Ньютона.
  const int NotWen = 5;
}
//! Размер карты от -ampleksoMapo до ampleksoMapo.
const int ampleksoMapo = 25;


#endif // __KONSTANTOJ_H__
