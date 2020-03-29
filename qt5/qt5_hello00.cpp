// ------------------------------------------------------------
// qt5_hello00.cpp
//
// Qt5 の実行サンプル
//
// ------------------------------------------------------------
#include<memory>
#include <QApplication>
#include <QLabel>
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;

    auto  hello1 = std::make_shared<QLabel>("猫");
    auto  hello2 = std::make_shared<QLabel>("ゾウ");
    auto  hello3 = std::make_shared<QLabel>("イルカ");
    auto  hello4 = std::make_shared<QLabel>("犬");

    // レイアウト
    QVBoxLayout *lyt = new QVBoxLayout();
    lyt->addWidget(hello1.get());
    lyt->addWidget(hello2.get());
    lyt->addWidget(hello3.get());
    lyt->addWidget(hello4.get());

    // ウインドウを表示
    w.setLayout(lyt);
    w.show();    

    return app.exec();
}
