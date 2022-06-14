#pragma once
#include <QObject>

class QThread;
class Monitor : public QObject {
  Q_OBJECT
 public:
  Monitor();
  ~Monitor();

  int Quit();
 public slots:
  void GatherAndAnalyze();

 signals:
  void SendAction(int no);

 private:
  QThread *thread_;
  int index_;
};
