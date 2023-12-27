# Метод конечных разностей
## Постановка задачи
Задача изначально имеет вид:

$$
\begin{equation*}
 \begin{cases}
   cc
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

$y' \sim \frac{y(x+h) - y(x-h)}{2h} \quad y'' \sim  \frac{y(x+h) - 2y(x) + y(x-h)}{h^2}$

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

Перепишем в матричном виде:




