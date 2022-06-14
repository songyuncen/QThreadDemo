#include "main_widget.h"

#include <QtWidgets>

#include "executor.h"
#include "monitor.h"

MainWidget::MainWidget() : monitor_(nullptr), executor_(nullptr) {
  SetupUI();
  connect(start_button_, SIGNAL(clicked(bool)), this, SLOT(Start(bool)));
}

MainWidget::~MainWidget() {}

void MainWidget::SetupUI() {
  QHBoxLayout *main_layout = new QHBoxLayout(this);
  start_button_ = new QPushButton(tr("Start"));
  start_button_->setCheckable(true);
  QPushButton *quit_button = new QPushButton(tr("Quit"));

  main_layout->addWidget(start_button_);
  main_layout->addWidget(quit_button);
  setFixedSize(250, 50);

  connect(quit_button, SIGNAL(clicked()), this, SLOT(Quit()));
}

void MainWidget::Start(bool checked) {
  if (checked) {
    qDebug() << (quintptr)QThread::currentThreadId() << " : "
             << "Start in MainWidget";
    start_button_->setText(tr("Stop"));
    monitor_ = new Monitor;
    executor_ = new Executor;
    connect(monitor_, SIGNAL(SendAction(int)), executor_, SLOT(DoAction(int)));
    connect(executor_, SIGNAL(NeedQuit()), this, SLOT(Quit()));
  } else {
    qDebug() << (quintptr)QThread::currentThreadId() << " : "
             << "Stop in MainWidget";
    start_button_->setText(tr("Start"));
    Quit(false);
  }
}

void MainWidget::Quit(bool immediate) {
  // first quit monitor
  int index = -1;
  if (monitor_) {
    index = monitor_->Quit();
    monitor_ = nullptr;
  }

  if (executor_) {
    if (immediate) {
      executor_->Quit(-1);
      executor_ = nullptr;
    } else {
      executor_->Quit(index);
    }
  }
  qDebug() << (quintptr)QThread::currentThreadId() << " : "
           << "Quit in MainWidget";

  start_button_->setChecked(false);
  start_button_->setText(tr("Start"));
}
