////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEViewCtrl.hpp"
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

YQ_TACHYON_IMPLEMENT(yq::tachyon::TEViewCtrl)

namespace yq::tachyon {
    TEViewCtrl::TEViewCtrl(QWidget* parent) : xwidget_type(parent)
    {
        QVBoxLayout*    layout  = new QVBoxLayout;
        
        QPushButton*    startBtn    =  new QPushButton(tr("Start"));
        QPushButton*    killBtn    =  new QPushButton(tr("Kill"));
        
        QHBoxLayout*    ctrlStrip   = new QHBoxLayout;
        ctrlStrip -> addWidget(startBtn);
        ctrlStrip -> addWidget(killBtn);
        layout->addLayout(ctrlStrip);
        setLayout(layout);
    }
    
    TEViewCtrl::~TEViewCtrl()
    {
    }
}

#include "moc_TEViewCtrl.cpp"
