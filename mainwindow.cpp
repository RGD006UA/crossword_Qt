#include "mainwindow.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
  : QWidget(parent) {
  putQuestions();
  buildSet();
  addBtn();

  hbox->addLayout(vboxQuestion);

  gridAnswers->setMargin(0);
  gridAnswers->setSpacing(0);
  gridAnswers->setContentsMargins(0, 0, 0, 0);

  hbox->addLayout(gridAnswers);
  hbox->addLayout(vboxBtn);

  connect(btnExit, &QPushButton::clicked, this, &QApplication::exit);
  connect(btnCheck, &QPushButton::clicked, this, checkWords);

  setLayout(hbox);
}

void MainWindow::putQuestions() {
  tLabel->setFont(f);
  tLabel->setText(m_question);
  vboxQuestion->addWidget(tLabel);
}

QLineEdit* MainWindow::createQLineEdit() {
  QLineEdit *temp = new QLineEdit(this);
  temp->setMaximumWidth(20);
  temp->setFont(f);
  temp->setMaxLength(1);
  connect(temp, &QLineEdit::textChanged, this, storeAnswer);
  return temp;
}

void MainWindow::storeAnswer() {
  QString str = static_cast<QLineEdit*>(sender())->text();
  if (!str.isEmpty())
    guess << str;
  else
    guess.pop_back();
}

void MainWindow::buildSet() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 20; ++j) {
      if (krosmodel[i][j] != ' ')
        gridAnswers->addWidget(createQLineEdit(), i, j);
    }
  }
}

void MainWindow::addBtn() {
  vboxBtn->addWidget(btnCheck, Qt::AlignBottom);
  vboxBtn->addWidget(btnExit, Qt::AlignBottom);
}

void MainWindow::checkWords() {
  QString answer = krosmodel.join("\0").simplified().replace(" ", "");
  if (answer == guess.join("\0"))
    tLabel->setText(m_question + "\n\nВітаю, ви все вгадали!");
  else
    tLabel->setText(m_question + "\n\nВи щось написали не вірно");
}