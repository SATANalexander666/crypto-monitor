# <p style="text-align: center;">Смотрящий за криптой</p>

---

## Описание проекта.

При помощи библиотек `cppzmq` и `pyzmq` - очереди сообщений `ZeroMQ`, осуществляется обмен информацией между клиентом и сервером.

### Клиент.

Полностью написанный на `C++` клиент отправляет запросы на сервер (посредством библиотеки `cppzmq`), получая ответы - позиции, полностью определяемые сервером, на основе которых строит графический интерфейс, используя библиотеку `Qt`.

### Сервер.

Полностью написанный на `Python` сервер получает запросы от клиента (посредством библиотеки `pyzmq`), используя библиотеку `requests` и свободный `Binance API` получает актуальные позиции, которые отправляет клиенту. В данной реализации сервер завёрнут в `Docker-`контейнер.

## Структура проекта.

> В квадратных скобках указывается относительное расположение файла, в котором реализован последующий класс, в перечислении - методы и аттрибуты класса, в круглых скобках - потомки.

### Клиент.

- [client/src/Reciever.cpp | client/include/Reciever.hpp] `TReciever` - класс, имплементирующий работу с сокетами библиотеки `pyzmq`, основывется на паттерне `REQ-REP`, реализует его запросную часть.

- [client/src/Reader.cpp | client/include/Reader.hpp] `TReader` - класс, имплементирующий чтение из файла (ранняя реализация общения между процессами).

> Классы `TReciever` и `TReader` взаимозаменяемы в описанной далее конструкции, реализован паттерн "Стратегия".

- [client/src/Parser.cpp | client/include/Parser.hpp] `TParser(TReciever | TReader)` - класс, имплементирующий парсинг информации, получаемой при помощи классов, описанных выше.

- [client/src/DataManager.cpp | client/include/DataManager.hpp] `TDataManager(TParser)` - класс, реализующий обновление и хранение информации в определённом формате.

> Посредством описанной выше структуры реализован паттерн "Цепочка обязанностей".

- [client/src/TableModel.cpp] `TTableModel(QAbstractTableModel)` - абстрактный класс, определяющий методы абстрактного класса `QAbstractTableModel`, отвечающего за содержимое таблицы, представляемой в графическом интерфейсе.

> Посредством абстрактного класса `TTableModel` реализован паттерн "Мост" между абстракцией `QAbstractTableModel` и её реализацией `TTableLinker`, описанной в следующем пункте.

- [client/src/TableLinker.cpp | client/include/TableLinker.hpp] `TTableLinker(TTableModel, TDataManager)` - класс, реализующий методы абстрактного класса `TTabelModel` и связывающий их с данными, хранящимися в классе `TDataManager`.

> Посредством класса `TTableLinker` реализован паттерн "посредник".

### Сервер.

- [server/server.py] `Sender` - класс, имплементирующий работу с сокетами библиотеки `pyzmq`, основывется на паттерне `REQ-REP`, реализует его ответную часть.
    + `send(str) -> None` 
    + `recieve() -> str`

- [server/server.py] `Updater` - класс, выполняющий функцию получения и парсинга информации в формате `.json`.
    + `update() -> list(str)`

- [server/server.py] `WSender` - класс реализующий замещающий паттерн, имеет контроль над классом `Sender`, фактически являясь для него родительским, позволяет использовать конструкцию `with ... as ...:`.

> Посредством класса `WSender` реализован паттерн "proxy".

- [server/server.py] `WUpdater` - класс реализующий замещающий паттерн, имеет контроль над классом `Updater`, фактически являясь для него родительским, позволяет использовать конструкцию `with ... as ...:`.

> Посредством класса `WUpdater` реализован паттерн "proxy".



https://user-images.githubusercontent.com/91434107/212758406-cf6dd419-6e81-4972-88ad-460463290081.mp4



---
<a href="https://www.flaticon.com/authors/tempo-doloe">Icons created by Tempo_doloe - Flaticon</a>
