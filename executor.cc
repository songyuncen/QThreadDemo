#include "executor.h"

#include <QThread>
#include <QDebug>

Executor::Executor() : thread_(nullptr) {
  thread_ = new QThread;
  moveToThread(thread_);

  connect(thread_, SIGNAL(finished()), this, SLOT(deleteLater()));
  thread_->start();
}

Executor::~Executor() {
  qDebug() <<(quintptr)QThread::currentThreadId() << " : "
           << "Deconstruction of Executor";
  thread_->deleteLater();
}

void Executor::DoAction(int no) { 
  qDebug() << (quintptr)QThread::currentThreadId() << " : "
           << "DoAction(" << no << ")";
}

void Executor::Quit() {
  qDebug() <<(quintptr)QThread::currentThreadId() << " : "
           << "Quit Executor";
  thread_->quit();
}

