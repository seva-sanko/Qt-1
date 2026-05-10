# Qt-1

Qt lab — dynamic widget collection with signals/slots (lab6).

Write a class that holds a resizable collection of widgets. A button dynamically adds new widgets to the collection; another button connects all widgets to each other via signals/slots so that interacting with one affects the others.

**Constraints:** widgets are NOT auto-connected on creation; connections are established on demand via `QMetaObject` (no `dynamic_cast`/`static_cast`). Connected widget types: `QLabel`, `QSlider`, `QScrollBar`, `QSpinBox`.

**Files:** `widgetcollection.h/.cpp` — collection class; `mainwindow.h/.cpp/.ui` — main window.
