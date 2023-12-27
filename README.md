# Метод конечных разностей

Задача изначально имеет вид:

$$
\begin{equation*}
 \begin{cases}
   \frac{d^2y}{dx^2} + sin(x)\frac{dy}{dx} + x^2y + x^2 = 0
   \\
   0 \leq x \leq 1,
   \\
   y(0) = 2,
   \\
   y(1) = 1.
 \end{cases}
\end{equation*}
$$

Построим для нее разностную схему:

$$y' \sim \frac{y(x+h) - y(x-h)}{2h}, \quad y'' \sim  \frac{y(x+h) - 2y(x) + y(x-h)}{h^2}$$

$$
\begin{equation*}
 \begin{cases}
   \frac{y_{i+1} - 2y_i + y_{i-1}}{h^2} + sin(x_i)\frac{y_{i+1} - y_{i-1}}{2h} + x_i^2y_i + x_i^2 = 0,
   \\
   0 \leq x \leq 1,
   \\
   y_0 = 2,
   \\
   y_N = 1.
 \end{cases}
\end{equation*}
$$

Преобразовывая, получаем:

$$
\begin{equation*}
 \begin{cases}
   (\frac{1}{h^2} + \frac{1}{2h}sin(x_i))y_{i+1} + (-\frac{2}{h^2})y_i + (\frac{1}{h^2} - \frac{1}{2h}sin(x_i))y_{i-1} = -x_i^2y - x_i^2,
   \\
   0 \leq x \leq 1,
   \\
   y_0 = 2,
   \\
   y_N = 1.
 \end{cases}
\end{equation*}
$$

Перепишем левую часть уравнения в матричном виде:

$$
\begin{pmatrix}
 -\frac{2}{h^2} & \frac{1}{h^2} + \frac{1}{2h}sin(x_0) & 0 & 0 & 0 & \ldots & 0 & 0 & 0 & 0 \\
\frac{1}{h^2} - \frac{1}{2h}sin(x_1) & -\frac{2}{h^2} & \frac{1}{h^2} + \frac{1}{2h}sin(x_1) & 0 &  0 & \ldots & 0 & 0 & 0 & 0 \\
0 & \frac{1}{h^2} - \frac{1}{2h}sin(x_2) & -\frac{2}{h^2} & \frac{1}{h^2} + \frac{1}{2h}sin(x_2) & 0 & \ldots  & 0 & 0 & 0 & 0 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
0 & 0 & 0 & 0 & 0 & \ldots & 0 & \frac{1}{h^2} - \frac{1}{2h}sin(x_{N-1}) & -\frac{2}{h^2} & \frac{1}{h^2} + \frac{1}{2h}sin(x_{N-1})\\
0 & 0 & 0 & 0 & 0 & \ldots & 0 & 0 & \frac{1}{h^2} - \frac{1}{2h}sin(x_N) & -\frac{2}{h^2}\\
     \end{pmatrix}
     \times
     \begin{pmatrix}
         y_0\\ 
         \vdots\\
         \vdots\\
         \vdots\\
         \vdots\\
         \vdots\\
         y_n\\ 
     \end{pmatrix}
$$

И правую соответственно:

$$
 \begin{pmatrix}
         - x_0^2y_0 - x_0^2\\ 
         - x_1^2y_1 - x_1^2\\ 
         \vdots\\
         \vdots\\
         \vdots\\
         - x_{N-1}^2y_{N-1} - x_{N-1}^2\\ 
         - x_N^2y_N - x_N^2
     \end{pmatrix}
 $$

 На первом шаге, учитывая начальные условия, получим  вид:

 $$
\begin{pmatrix}
1 & 0 & 0 & 0 & 0 & \ldots & 0 & 0 & 0 & 0 \\
\frac{1}{h^2} - \frac{1}{2h}sin(x_1) & -\frac{2}{h^2} & \frac{1}{h^2} + \frac{1}{2h}sin(x_1) & 0 &  0 & \ldots & 0 & 0 & 0 & 0 \\
0 & \frac{1}{h^2} - \frac{1}{2h}sin(x_2) & -\frac{2}{h^2} & \frac{1}{h^2} + \frac{1}{2h}sin(x_2) & 0 & \ldots  & 0 & 0 & 0 & 0 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
0 & 0 & 0 & 0 & 0 & \ldots & 0 & \frac{1}{h^2} - \frac{1}{2h}sin(x_{N-1}) & -\frac{2}{h^2} & \frac{1}{h^2} + \frac{1}{2h}sin(x_{N-1})\\
0 & 0 & 0 & 0 & 0 & \ldots & 0 & 0 & 0 & 1\\
     \end{pmatrix}
     \times
     \begin{pmatrix}
         y_0\\ 
         \vdots\\
         \vdots\\
         \vdots\\
         \vdots\\
         \vdots\\
         y_n\\ 
     \end{pmatrix}
$$

и

$$
 \begin{pmatrix}
         2\\ 
         - 2x_1^2 - x_1^2\\ 
         \vdots\\
         \vdots\\
         \vdots\\
         - 2x_{N-1}^2 - x_{N-1}^2\\ 
         2
     \end{pmatrix}
 $$

 Первую матрицу обозначим за A. найдем обратную к ней(Для нахождения обратной матрицы используется метод Гаусса) и обозначим ее за $A^{-1}$.
 Далее умножаем обе части уравнения на обратную матрицу $A^{-1}$ слева. Получим выражение:

$$
 \begin{pmatrix}
         y_0\\ 
         y_1\\
         \vdots\\
         \vdots\\
         y_{N-1}\\
         y_N\\ 
     \end{pmatrix}
     \times
     A^{-1}
      =
     \begin{pmatrix}
         2\\ 
         -2x_1^2 - x_1^2\\ 
         \vdots\\
         \vdots\\
         -2x_{N-1} - x_{N-1}^2\\ 
         2\\ 
     \end{pmatrix}
     $$

Далее запускаем итерационный процесс:

$$
  \begin{pmatrix}
          y_0^{k+1}\\ 
          y_1^{k+1}\\
          \vdots\\
          \vdots\\
          y_{N-1}^{k+1}\\
          y_N^{k+1}\\ 
      \end{pmatrix}
      \times
      A^{-1}
       =
      \begin{pmatrix}
          2\\ 
          -x_1^2y_1^k - x_1^2\\ 
          \vdots\\
          \vdots\\
          -x_{N-1}y_{N-1}^k- x_{N-1}^2\\ 
          2\\ 
      \end{pmatrix}
      $$

Заканчиваем этот процесс либо по условию $dist(y^k, y^{k+1}) = \sum\limits_{i=0}^nh(y_i^{k+1} - y_i^k)^2 < 10^{-6}$ либо по количеству итераций

