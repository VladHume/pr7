# pr7

## Завдання 1
Мета: Передати вивід команди `rwho` через `popen()` до команди `more`.

[Код](https://github.com/VladHume/pr7/blob/main/task1.c)
```sh
gcc -Wall -o task1 task1.c
./task1
```
Результат: Програма запускає команду і передає її результат на екран через `more`.

![image](https://github.com/user-attachments/assets/54d1b221-f9f9-467f-b0d5-d1b7834b79d7)


## Завдання 2
Мета: Імітувати роботу `ls -l` без виклику команди через системні засоби.

[Код](https://github.com/VladHume/pr7/blob/main/task2.c)
```sh
gcc -Wall -o task2 task2.c
./task2
```

Результат: Виводяться файли, їхні права доступу, розмір, дата та власник.

![image](https://github.com/user-attachments/assets/f0939ab4-a6af-4265-ae73-78c596d7fe54)

## Завдання 3
Мета: Створити спрощену версію `grep`.

[Код](https://github.com/VladHume/pr7/blob/main/task3.c)
```sh
gcc -Wall -o task3 task3.c
./task3 popen task1.c
```

Результат: Програма шукає слово у вказаному файлі та виводить рядки, що його містять.

![image](https://github.com/user-attachments/assets/654bdd1b-83ae-49bc-8ab0-1372a3d6c979)

## Завдання 4
Мета: Спрощена версія `more`.

[Код](https://github.com/VladHume/pr7/blob/main/task4.c)
```sh
gcc -Wall -o task4 task4.c
./task4 task7.c
```

Результат: Вивід файлів з паузою кожні 20 рядків.

![image](https://github.com/user-attachments/assets/10053919-d78c-4a02-b7d7-cb7f0e2e4309)

![image](https://github.com/user-attachments/assets/faa16ba9-1bf7-4e63-9a7a-96c5c2e59c64)

## Завдання 5
Мета: Рекурсивний обхід каталогів.

[Код](https://github.com/VladHume/pr7/blob/main/task5.c)
```sh
gcc -Wall -o task5 task5.c
./task5
```

Результат: Перелік усіх файлів та підкаталогів.

![image](https://github.com/user-attachments/assets/fd810f5d-964f-46d3-b60d-0c5d98841ed4)

## Завдання 6
Мета: Вивести лише підкаталоги у алфавітному порядку.

[Код](https://github.com/VladHume/pr7/blob/main/task6.c)
```sh
gcc -Wall -o task6 task6.c
./task6
```

Результат: Відсортований список підкаталогів.

![image](https://github.com/user-attachments/assets/8852ccc0-eafb-4bcb-8490-ab017264a8b1)

## Завдання 7
Мета: Надати читацькі права іншим користувачам на C-файли за згодою користувача.

[Код](https://github.com/VladHume/pr7/blob/main/task7.c)
```sh
gcc -Wall -o task7 task7.c
./task7
```

Результат: Програма запитує дозвіл на зміну прав та за потреби змінює права доступу.

![image](https://github.com/user-attachments/assets/1fd8cc29-1c73-4470-b19b-9654cb84ba93)

## Завдання 8
Мета: Інтерактивне видалення файлів.

[Код](https://github.com/VladHume/pr7/blob/main/task8.c)
```sh
gcc -Wall -o task8 task8.c
./task8
```

Результат: Користувач може підтвердити або скасувати видалення файлів.

![image](https://github.com/user-attachments/assets/47e8a862-8cfb-43ee-b0ac-9a2b9d5f5eca)

## Завдання 9
Мета: Виміряти час виконання коду у мілісекундах.

[Код](https://github.com/VladHume/pr7/blob/main/task9.c)
```sh
gcc -Wall -o task9 task9.c
./task9
```

Результат: Застосовано `gettimeofday()`, отримано час виконання у мс.

![image](https://github.com/user-attachments/assets/6d168360-5beb-4e05-8371-178a0fbec337)

## Завдання 10
Мета: Створити генератор рандомних чисел з плаваючою комою заданих діапазонів.

[Код](https://github.com/VladHume/pr7/blob/main/task10.c)
```sh
gcc -Wall -o task10 task10.c
./task10 9.3
```

Результат: Створено генератор чисел у діапазоні [0.0, 1.0] та [0.0, n].

![image](https://github.com/user-attachments/assets/e29fade1-7879-4302-8e02-cf88e7a28f0c)

## Завдання 11
Мета: Імітувати роботу черги задач з паузою, скасуванням та відновленням.

[Код](https://github.com/VladHume/pr7/blob/main/task11.c)
```sh
gcc -Wall -o task11 task11.c
./task11
```

Результат: Створено інтерактивний інтерфейс для керування станами задач без використання потоків та сигналів.

![image](https://github.com/user-attachments/assets/67b7df11-b5af-4193-a726-2b57acdd149a)
