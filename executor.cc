#include "executor.h"

#include <QDebug>
#include <QThread>

Executor::Executor() : thread_(nullptr) {
  thread_ = new QThread;
  moveToThread(thread_);

  connect(thread_, SIGNAL(finished()), this, SLOT(deleteLater()));
  thread_->start();
}

Executor::~Executor() {
  qDebug() << (quintptr)QThread::currentThreadId() << " : "
           << "Deconstruction of Executor";
  thread_->deleteLater();
}

void Executor::DoAction(int no) {
  QThread::sleep(2);
  qDebug() << (quintptr)QThread::currentThreadId() << " : "
           << "DoAction(" << no << ")";
  if (index_ > 0) {
    if (no >= index_) {
      emit NeedQuit();
    }
  }
}

void Executor::Quit(int index) {
  qDebug() << (quintptr)QThread::currentThreadId() << " : "
           << "Quit Executor with " << index;
  if (index < 0) {
    thread_->quit();
  } else {
    index_ = index;
  }
}
