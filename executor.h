#pragma once
#include <QObject>
#include <QAtomicInt>
class QThread;

class Executor : public QObject {
  Q_OBJECT
 public:
  Executor();
  ~Executor();

 public slots:
  void DoAction(int no);
  void Quit(int index = -1);

signals:
  void NeedQuit();

 private:
  QThread *thread_;
  QAtomicInt index_;
};
