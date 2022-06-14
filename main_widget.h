#pragma once

#include <QWidget>

class QPushButton;

class MainWidget : public QWidget {
  Q_OBJECT
 public:
  MainWidget();
  ~MainWidget();

 public slots:
  void Start(bool checked);
  void Quit();

 private:
  void SetupUI();

  QPushButton *start_button_;
};
