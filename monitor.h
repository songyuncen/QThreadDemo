#pragma once
#include <QObject>

class QThread;
class Monitor : public QObject {
  Q_OBJECT
 public:
  Monitor();
  ~Monitor();

 public slots:
  void GatherAndAnalyze();
  void Quit();

 signals:
  void SendAction(int no);

 private:
  QThread *thread_;
};
