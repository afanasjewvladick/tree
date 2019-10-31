# Утилита "tree"

## Описание
Утилита может выводить дерево каталогов и файлов.

## Компиляция 

``` bash
# compilation
$ make assembly

# создание или обновление символической ссылки
$ make link-create

# удаление символической ссылки
$ make link-delete


```

## Пример вывода

### с опцией -f (показывать файлы)
```
├── tree.php (423b)
├── Tree.php (1487b)
├── TreeTest.php (1986b)
└── data
    ├── dist
    │   ├── css
    │   │   └── app.css (14b)
    │   ├── html
    │   │   └── index.html (15b)
    │   └── js
    │       └── app.js (13b)
    ├── empty.txt (empty)
    └── src
        ├── vue
        │   └── main.js (20b)
        └── zzz.txt (21b)
```

### без опции -f (не показывать файлы)
```
└── data
    ├── dist
    │   ├── css
    │   ├── html
    │   └── js
    └── src
        └── vue
```

Задача взята с [Тестовые задания Ареал](https://github.com/areal-team/tz)