#pragma once
#include <QObject>

class QThread;

class Executor : public QObject {
  Q_OBJECT
 public:
  Executor();
  ~Executor();

 public slots:
  void DoAction(int no);
  void Quit();

 private:
  QThread *thread_;
};
