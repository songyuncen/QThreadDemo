#include "monitor.h"

#include <QDebug>
#include <QThread>
#include <QTimer>

Monitor::Monitor() {
  index_ = 0;
  thread_ = new QThread;
  QTimer *timer = new QTimer;
  timer->setSingleShot(false);
  timer->setInterval(500);

  timer->moveToThread(thread_);
  moveToThread(thread_);

  connect(timer, SIGNAL(timeout()), this, SLOT(GatherAndAnalyze()));

  connect(thread_, SIGNAL(started()), timer, SLOT(start()));
  connect(thread_, SIGNAL(finished()), timer, SLOT(deleteLater()));
  connect(thread_, SIGNAL(finished()), this, SLOT(deleteLater()));

  thread_->start();
}

Monitor::~Monitor() {
  qDebug() << (quintptr)QThread::currentThreadId() << " : "
           << "Deconstruction of Monitor";
  thread_->deleteLater();
}

void Monitor::GatherAndAnalyze() {
  emit SendAction(index_);
  qDebug() << (quintptr)QThread::currentThreadId() << " : "
           << "GatherAndAnalyze " << index_;
  index_++;
}

int Monitor::Quit() {
  qDebug() << (quintptr)QThread::currentThreadId() << " : "
           << "Quit Monitor";
  thread_->quit();
  return index_ - 1;
}