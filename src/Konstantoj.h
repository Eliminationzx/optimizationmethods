#ifndef __KONSTANTOJ_H__
#define __KONSTANTOJ_H__

//! Константы обозначающие алгоритм.
namespace A{
  //! Покоординатный спуск с фиксированным шагом.
  const int CWdescent_fix = 0;
  //! Покоординатный спуск
  const int CWdescent_md = 1;
  //! Наискорейший спуск.
  const int FasterDescent = 2;
  //! Алгоритм Хюга-Дживса.
  const int HuGi = 3;
  //! Алгоритм Нелдора-Мида.
  const int NeMiImpl = 4;
  //! Алгоритм Ньютона
  const int NotWen = 5;
}

#endif // __KONSTANTOJ_H__
