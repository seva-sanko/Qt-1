# Qt-1

Цель: написать собственный класс, который содержит единую коллекцию из виджетов динамического размера.

Создать метод и кнопку динамического добавления элементов интерфейса в коллекцию, а также метод и кнопку для соединения между собой всех помещенных в коллекцию виджетов с помощью механизма сигналов/слотов, чтобы действие с одним из них отображалось на других.

Обязательные ограничения при выполнении задания:
  -все новые виджеты автоматически НЕ соединяются;
  -виджеты из коллекции должны быть соединены напрямую через сигналы/слоты без использования прокси методов или классов;
  -для определения типа класса использовать QMetaObject, а не цепочку из cast преобразований.
  
Через функции отладки проверить, что соединения между объектами не дублируется многократно, и отсутствуют "висячие" соединения

Использовать виджеты следующих классов для соединения: QLabel, QSlider, QScrollbar, QSpinBox. Чтобы определить к какому классу относится объект использовать метаинформацию. 

Запрещается использовать static/dynamic_cast и виртуальные методы.
