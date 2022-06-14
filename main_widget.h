#pragma once

#include <QWidget>

class QPushButton;
class Monitor;
class Executor;

class MainWidget : public QWidget {
  Q_OBJECT
 public:
  MainWidget();
  ~MainWidget();

 public slots:
  void Start(bool checked);
  void Quit(bool immediate = true);

 private:
  void SetupUI();

  QPushButton *start_button_;
  Monitor *monitor_;
  Executor *executor_;
};
