////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MainWindow.hpp"
#include <yq/vkqt/app/YMainMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(MainWindow)

void MainWindow::init_meta()
{
    auto w = writer<MainWindow>();
    w.description("Executive Flow Graph Main Window");
}

MainWindow::MainWindow()
{
    setWindowTitle("Executive Graph");
    resize(1920, 1080);
}

MainWindow::~MainWindow()
{
}

#include "moc_MainWindow.cpp"
