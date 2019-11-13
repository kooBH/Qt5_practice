#include <QtWebEngineCore>
#include <QApplication>
#include <QWebEngineView>

#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>

QUrl commandLineUrlArgument()
{
  const QStringList args = QCoreApplication::arguments();
  for (const QString &arg : args.mid(1)) {
    if (!arg.startsWith(QLatin1Char('-')))
      return QUrl::fromUserInput(arg);
  }
  return QUrl(QStringLiteral("http://iip.sogang.ac.kr"));
}

int main(int argc, char *argv[])
{
  QCoreApplication::addLibraryPath("../lib");


  QCoreApplication::setOrganizationName("QtExamples");
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication app(argc, argv);

  QWidget widget_main;
  QVBoxLayout layout_main;
  QPushButton btn_scroll("scroll to bottom");
  QWebEngineView view_main;

  widget_main.setLayout(&layout_main);

  layout_main.addWidget(&btn_scroll);
  layout_main.addWidget(&view_main);

  view_main.setUrl(commandLineUrlArgument());
  view_main.resize(1024, 750);
  widget_main.show();

  QObject::connect(&btn_scroll, &QPushButton::clicked,
      [&](){
      /*
      view_main.page()->runJavaScript("\
          var scrollingElement = (document.scrollingElement || document.body);\
          scrollingElement.scrollTop = scrollingElement.scrollHeight;\
          ");
      */
      view_main.page()->runJavaScript(" window.scrollTo(0,document.body.scrollHeight);");

  //    view_main.page()->runJavaScript(  "window.scrollTo(500, 500);");

      }
      );


  app.exec();
  return 0;

}
