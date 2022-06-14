#include "main_widget.h"

#include <QtWidgets>

MainWidget::MainWidget() {
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
    qDebug() << "Start";
    start_button_->setText(tr("Stop"));
  } else {
    qDebug() << "Stop";
    start_button_->setText(tr("Start"));
  }
}

void MainWidget::Quit() { qDebug() << "Quit"; }

