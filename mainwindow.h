#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QVector>
#include <QLineEdit>
#include <QGridLayout>
#include <QBoxLayout>

class MainWindow : public QWidget
{
  Q_OBJECT
private:
  QStringList krosmodel{
      "сонячні кларнети    ",
      "        липа        ",
      "        арфа        ",
      "    модерніст       ",
      "     чернігів       ",
      "   кларнет          ",
      "        тоталітаризм",
      "    піски           ",
      "      музика        ",
      "        метафора    ",
  };
  QStringList guess;

  QString m_question = "Перша Збірка\nЯке дерево з'являється у першому друкованому творі?\nНа якому струнному інструменті вмів грати Павло?\nКим був письменник представляючи найвідомішу течію літератури ХХ ст?\nВ якому місті навчався Тичина\nЯкий духовий інструмент полюбляв митець?\nЩо зламало його життя з приходу СРСР\nДе народився Павлуша\nВ якому виді мистецтва він також був обдарованим?\n'Сплять старі гаї' - це...";

  QGridLayout* ask_grid = new QGridLayout;
  QHBoxLayout* hbox = new QHBoxLayout;
  QGridLayout* gridAnswers = new QGridLayout;
  QVBoxLayout* vboxQuestion = new QVBoxLayout;
  QPushButton* btnExit = new QPushButton("Вийти", this);
  QPushButton* btnCheck = new QPushButton("Перевірити відповіді", this);
  QVBoxLayout* vboxBtn = new QVBoxLayout;
  QLabel *tLabel = new QLabel(this);
  QFont f = QFont("Times New Roman", 14);

  void checkWords();
  void buildSet();
  void putQuestions();
  void addBtn();
  void storeAnswer();
  QLineEdit* createQLineEdit();
public:
  MainWindow(QWidget *parent = nullptr);
};
#endif // MAINWINDOW_H
